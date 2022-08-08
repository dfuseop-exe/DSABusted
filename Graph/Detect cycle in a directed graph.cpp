class Solution {
  public:
    bool isCycleDirected(int src , vector<int> adj[] , unordered_map<int , bool> &visited , unordered_map<int , bool> &DFSvisited){
        DFSvisited[src] = true ;
        visited[src] = true ;
        
        for(auto i : adj[src]){
            if(visited[i] == true && DFSvisited[i] == true ){
                return true ;
            }else if(!visited[i]){
                //DFSvisited[i] = true ;
                bool ans = isCycleDirected(i , adj , visited ,DFSvisited) ;
                if(ans == true){
                    return true ;
                }
                //DFSvisited[i] = false ;
            }
        }
        
        DFSvisited[src] = false ;
        
        return false ;
    }
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        unordered_map<int , bool> visited ; 
        unordered_map<int , bool> DFSvisited ;
        for(int i = 0 ; i < V ; i++){
            if(!visited[i]){
                bool ans = isCycleDirected(i , adj , visited , DFSvisited) ;
                if(ans == true){
                    return true ;
                }
            }
        }
        
        return false ;
    }
};