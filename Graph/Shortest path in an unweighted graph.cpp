#include<queue>
#include<unordered_map>
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	//step 1 - create adjcency list
    unordered_map<int , vector<int>> adj ;
    for(int i = 0 ; i <  m; i++){
        int u = edges[i].first ;
        int v = edges[i].second ;
        
        //as this is undirected graph
        adj[u].push_back(v) ;
        adj[v].push_back(u) ;  
    }
    
    //step 2 - bfs algo to create a parent data structure
    unordered_map<int , bool> visited ;
    unordered_map<int , int> parent ;
    queue<int> q ;
    
    //src node 
    q.push(s) ;
    visited[s] = true ;
    parent[s] = -1 ;
    
    while(!q.empty()){
        int frontNode = q.front() ;
        q.pop() ;
        
        //get all adjecent node
        for(auto i : adj[frontNode]){
            if(!visited[i]){
                q.push(i) ;
                visited[i] = true ;
                parent[i] = frontNode ;
            }
        }
    }
    
    //get shortest path
    int currentNode = t ; //t is destination node
    vector<int> path ;
    path.push_back(t) ;
    
    while(currentNode != s){
        currentNode = parent[currentNode] ;
        path.push_back(currentNode) ;
    }
    
    reverse(path.begin() , path.end()) ;
    return path ;
}
