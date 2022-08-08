#include<unordered_map> 

void getAdj(unordered_map<int , vector<int> > &adj , vector<vector<int>> &edges){
    for(int i = 0 ; i < edges.size() ; i++){
        int u = edges[i][0] ;
        int v = edges[i][1] ;
        
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }
}

void dfs(int node , unordered_map<int , vector<int> > &adj , unordered_map<int , bool> &visited , vector<int> &component){
    //step 1 
    //store current node
    component.push_back(node) ;
    visited[node] = true ;
    
    for(auto i : adj[node]){
        if(!visited[i]){
            dfs(i , adj , visited , component) ;
        }
    }
}

vector<vector<int>> depthFirstSearch(int V, int E, vector<vector<int>> &edges)
{
    unordered_map<int , vector<int> > adj ;
    vector<vector<icomponentnt>> ans ;
    unordered_map<int , bool> visited ; 
    
    getAdj(adj , edges) ;
    
    for(int i = 0 ; i<V ; i++){
        vector<int>   ;
        if(!visited[i]){
            dfs(i , adj , visited , component) ;
            ans.push_back(component) ;
        }
        
    }
    
    return ans ;
}