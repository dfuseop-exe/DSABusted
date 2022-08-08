class Solution {
  public:
  
     
    
    void getbfs(vector<int> adj[]  , unordered_map<int , bool > &visited , vector<int> &ans , int node){
        queue<int> q ;
        q.push(node) ;
        visited[node] = true ;
        
        while(!q.empty()){
            int frontNode = q.front() ;
            q.pop() ;
            
            //store in ans
            ans.push_back(frontNode) ;
            
            //push all nodes that are adj to frontNode
            //frontNOde -> 1 2 3 so i means this 1 2 3 
            for(auto i : adj[frontNode]){
                //check is this already present ?
                if(!visited[i]){
                    q.push(i) ;
                    visited[i] = true ;
                }
            }
        }
    }

    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        unordered_map<int , bool > visited ;
        vector<int> ans ;
        
        //use set over list or vector coz we need traversal ans in sorted way like for adj nodes 

        //now print bfs 
        //as this is not disconnected graph so we did not need to iterate over all vertex 
        
            if(!visited[0]){
                getbfs(adj , visited , ans , 0) ;
            }
        
        return ans ;
    }
};