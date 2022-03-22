
class Solution
{
    public:
    //Function to return the level order traversal of a tree.
    vector<int> levelOrder(Node* node)
    {
        //storing element of level
            vector<int> level; 
          
        //if condition is true return empty ans
        if(node == NULL) return level; 
        
        //create a queue and push root node
        queue<Node*> q; 
        q.push(node); 
        
        //now process untill queue become empty
        while(!q.empty()) {
                
                Node* curr = q.front();
                q.pop();
                
                
                
                if(curr-> left != NULL){
                    q.push(curr-> left) ;
                }
                
                if(curr-> right != NULL){
                    q.push(curr-> right) ;
                }
                
                level.push_back(curr->data);
            }
        
        return level; 
    }
};