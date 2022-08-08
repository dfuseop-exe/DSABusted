class Solution {
  public:
  
    void dfs(vector<int> adj[] ,vector<int> &ans , unordered_map<int , bool > &visited  ,int node){
        ans.push_back(node) ;
        visited[node] = true ;
        
        for(auto i : adj[node]){
            if(!visited[i]){
                dfs(adj , ans , visited , i) ;
            }
        }
    }
    
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        unordered_map<int , bool > visited ;
        vector<int> ans ;
        
        if(!visited[0]){
            dfs(adj , ans , visited , 0) ;
        }
        
        return ans ;
    }
};
