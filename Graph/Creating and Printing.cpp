vector < vector < int >> printAdjacency(int n, int m, vector < vector < int >> & edges) {    

//What does vector int v [] means?
// vector<int> v[] is an array of vectors. That is, it is an array which contains vectors as its elements. So, you cannot change the size of the array part, but we can add to its elements which is vector.
    vector<int> ans[n] ;
    
    for(int i = 0 ; i < m ; i++){
        
        int u = edges[i][0] ;
        int v = edges[i][1] ;
        
        ans[u].push_back(v) ;
        ans[v].push_back(u) ;
    }
    
    vector < vector < int >> adj(n) ;
    
    for(int i = 0 ; i < n ; i++){
        adj[i].push_back(i) ;
        
        for(int j = 0 ; j < ans[i].size() ; j++){
            adj[i].push_back(ans[i][j]) ;
        }
    }
    
    return adj ;
}
