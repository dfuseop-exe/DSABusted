class Solution {
  public:
    vector <int> bottomView(Node *root) {
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
            
            
            //maintain 1-1 map if one mapping is present then overwrite new entry 
            //as we want bottom entry 

            topnode[hd] = frontNode-> data ;
      
            
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