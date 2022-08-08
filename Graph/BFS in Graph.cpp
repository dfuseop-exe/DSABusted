/* 
    steps - 
    create required ds
    create adj list using given edges 
    print bfs
*/
#include<unordered_map>
#include<set>
#include<queue>

void getAdj(unordered_map<int , set<int> > &adj , vector<pair<int, int>> &edges){
    //we have edges 
    /*
        vector[
                    first , second
           pair 1- (2-3)
            2- (8-3) 
        ]
    */
    
    for(int i = 0 ; i < edges.size() ; i++){
        int u = edges[i].first ;
        int v = edges[i].second ;
        
        //add in adj
        adj[u].insert(v) ;
        adj[v].insert(u) ;
    }
}

void getbfs(unordered_map<int , set<int> > adj  , unordered_map<int , bool > &visited , vector<int> &ans , int node){
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

vector<int> BFS(int vertex, vector<pair<int, int>> edges)
{
    unordered_map<int , bool > visited ;
    vector<int> ans ;
    
    //use set over list or vector coz we need traversal ans in sorted way like for adj nodes 
    unordered_map<int , set<int> > adj ;
    
    getAdj(adj , edges) ;
    
    //now print bfs 
    //as this is disconnected graph so we need to iterate over all vertex 
    for(int i = 0 ; i < vertex ; i++){
        if(!visited[i]){
            getbfs(adj , visited , ans , i) ;
        }
    }
    
    return ans ;
}
