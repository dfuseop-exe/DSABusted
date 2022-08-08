#include<unordered_map>
#include<limits.h>

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    // step 1 - create adj list
    unordered_map<int , vector<pair<int,int>>> adj ;
    
    for(int i = 0 ; i < g.size() ; i++){
        int u = g[i].first.first ;
        int v = g[i].first.second ;
        int w = g[i].second ;
        
        //undirected
        adj[u].push_back({v,w}) ;
        adj[v].push_back({u,w}) ;   
    }
    
    //step - 2 - create data structure [ n+1 coze we are using index as node so nodes are starting from 1 thats Y]
    vector<int> key(n+1) ;
    vector<int> parent(n+1) ;
    vector<bool> mst(n+1) ;
    
    //step - 3 - initialise 
    for(int i = 1 ; i <= n ; i++){
        key[i] = INT_MAX ;
        parent[i] = -1 ;
        mst[i] = false ;
    }
    
    //step - 4 - initialise source node
    int source = 1 ;
    key[source] = 0 ; //as distance from 0->0 is 0
    
    //process all node to process
    for(int i = 0 ; i < n ; i++){
        
        //step - 5 - find minimum distance or key array
        int mini = INT_MAX ;
        int node ;
        
        for(int v = 1 ; v <= n ; v++){
            if(mst[v] == false && key[v] < mini){
                node = v ; //smallest distance node
                mini = key[v] ;
            }
        }
        
        //marking
        mst[node] = true ;
        
        //check adj
        for(auto it : adj[node]){
            //calculate smaller value for src to adj weight 
            if(it.second < key[it.first] && mst[it.first] == false){
                //assign new smallest value
                key[it.first] = it.second  ;
                parent[it.first] = node ;
            }
        }
    }
    
      vector<pair<pair<int, int>, int>> result ;
        for(int i = 2 ; i <= n ; i++){
            result.push_back({{parent[i] , i} , key[i]}) ;
        }
        return result ;
}
