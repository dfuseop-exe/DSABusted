class Solution {
public:
    void dfs(int node , int &timer , int parent , unordered_map<int , vector<int>> &adj ,
         unordered_map<int, bool> &visited , vector<int> &discoveryTime , vector<int> &lowTime , 
         vector<vector<int>> &result){
    
    //dfs wala flow
    visited[node] = true ;
    
    //initially value of nodes are = timer
    discoveryTime[node] = lowTime[node] = timer ;
    
    timer++ ; //increment time as this node is reached
    
    //find adj as we do in dfs
    for(auto i : adj[node]){
        if(i == parent){
            continue ; //ignore as algo states 
        }else if(!visited[i]){
            dfs(i , timer , node , adj , visited , discoveryTime , lowTime , result) ;
            
            //when we returning make sure to change lowTimeof node 
            lowTime[node] = min(lowTime[node] , lowTime[i]) ;
            
            //also check is this bridge node ?
            if(discoveryTime[node] < lowTime[i]){
                vector<int> ans ;
                ans.push_back(node) ;
                ans.push_back(i) ;
                result.push_back(ans) ;
            }
        }else{
            //it is visited means it is a Back edge 
            lowTime[node] = min(lowTime[node] , discoveryTime[i]) ; //formaula
        }
    }
    
}
    
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        //create adj list
        unordered_map<int , vector<int>> adj ;
        for(int i = 0 ; i < connections.size() ; i++){
            int u = connections[i][0] ;
            int v = connections[i][1] ;

            //undirected
            adj[u].push_back(v) ;
            adj[v].push_back(u) ;
        }

        //required Ds
        int timer = 0 ;
        vector<int> discoveryTime(n , -1) ;
        vector<int> lowTime(n , -1) ;
        unordered_map<int, bool> visited ;
        int parent = -1 ;
        vector<vector<int>> result ;

        //dfs 
        for(int i = 0 ; i < n ; i++){
            if(!visited[i]){
                dfs(i , timer , parent , adj , visited , discoveryTime , lowTime , result ) ;
            }
        }

        return result ;
    }
};