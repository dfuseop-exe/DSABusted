class Solution
{
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        //ans
        vector<int> ans ;
        
        if(root == NULL)
            return ans ;
        
        //we have to map HD -> node
        map<int,int> topnode ;
        queue<pair<Node*,int> > q ;
        
        q.push(make_pair(root,0)) ;
        
        while(!q.empty()){
            pair<Node*,int> temp = q.front() ;
            q.pop() ;
            
            //node
            Node* frontNode = temp.first ;
            int hd = temp.second ;
            
            
            //maintain 1-1 map if one mapping is present then ignore remaining entries
            //finding entry if not getting it will return topnode.end() value means first entru
            if(topnode.find(hd) == topnode.end()){
                topnode[hd] = frontNode-> data ;
            }
            
            if(frontNode-> left){
                q.push(make_pair(frontNode-> left , hd-1)) ;
            }
            
            if(frontNode-> right){
                q.push(make_pair(frontNode-> right , hd+1)) ;
            }
        }
        
        for(auto i : topnode){
            ans.push_back(i.second) ;
        }
        
        return ans ;
    }

};