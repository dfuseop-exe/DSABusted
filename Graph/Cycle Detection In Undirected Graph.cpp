#include<unordered_map>
#include<queue>


bool isCyclicBfs(int src ,unordered_map<int , bool> &visited , unordered_map<int , vector<int> > &adj ){
    unordered_map<int , int> parent ;
    queue<int> q ;
    
    parent[src] = -1 ;
    visited[src] = true ;
    
    q.push(src) ;
    
    while(!q.empty()){
        int front = q.front() ;
        q.pop() ;
        
        for(auto neighbour : adj[front]){
            if(visited[neighbour] == true && neighbour != parent[front]){
                return true ;
            }else if(!visited[neighbour]){
                q.push(neighbour) ;
                parent[neighbour] = front ;
                visited[neighbour] = true ;
            }
        }
    }
    
    return false ;
}

string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    unordered_map<int , vector<int> > adj ;
    
    for(int i = 0 ; i < edges.size() ; i++){
        int u = edges[i][0] ;
        int v = edges[i][1] ;
        
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;
    }
    
    unordered_map<int , bool> visited ;
    
    
    for(int i = 0 ; i < n ; i++){
        if(!visited[i]){
            bool ans = isCyclicBfs(i , visited , adj) ;
            
            if(ans == true){
                return "Yes" ;
            }
        }
    }
    
    return "No" ;
}
