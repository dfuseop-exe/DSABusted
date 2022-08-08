#include<unordered_map>
#include<set>
#include<list>
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
    //create adj list
    unordered_map<int , list<pair<int,int>> > adj ;
    for(int i = 0 ; i < edges ; i++){
        int u = vec[i][0] ;
        int v = vec[i][1] ;
        int w = vec[i][2] ;
        
        //as this is undirected 
        adj[u].push_back(make_pair(v,w)) ;
        adj[v].push_back(make_pair(u,w)) ;
    }
    
    //create distance vector
    vector<int> distance(vertices) ;
    for(int i = 0 ; i < vertices ; i++){
        distance[i] = INT_MAX ;
    }
    
    distance[source] = 0 ; //imp 
    
    //create & insert pair in set as {weight ,node}
    set<pair<int , int>> st ;
    st.insert({0,source}) ;
    
    //process dijkstra's 
    while(!st.empty()){
        //fetch top node of set
        auto top = *(st.begin()) ;
        
        //get values from top node
        int node = top.second ;
        int weight = top.first ;
        
        //remove top of set
        st.erase(st.begin()) ;
        
        //traverse adj list of topNode 
        for(auto i : adj[node]){
            
            //if any change is there the we have to consider this case
            //as our adj format is  adj[u].push_back(make_pair(v,w)) ;
            if(weight + i.second < distance[i.first]){
               
                auto record = st.find({distance[i.first] , i.first}) ;
                
                //if record found
                if(record != st.end()){
                    st.erase(record) ;
                }
                
                //calculate distance
                distance[i.first] = weight + i.second ;
                
                //add entry in set for this adj node
                st.insert({distance[i.first] , i.first}) ;
                
            }
        }
    }
    
    return distance ;
}
