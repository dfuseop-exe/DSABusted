vector<int> diagonal(Node *root)
{
    //for storing ans
    vector<int> ans ;
    queue<Node*> q ;
    
    if(root == NULL){
       return ans ;
    }
    
    q.push(root) ;
    
    while(!q.empty()){
        //pop root nd front node
        Node* frontNode = q.front();
        q.pop();
        
        //check is not null
        while(frontNode){
            //store data
            ans.push_back(frontNode-> data) ;
            //left exists push in queue
            if(frontNode-> left){
                q.push(frontNode-> left) ;
            }
            //go right
            frontNode = frontNode-> right ;
        }
    }
    
    return ans ;
}