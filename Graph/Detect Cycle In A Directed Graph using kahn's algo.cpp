#include<queue>
#include<unordered_map>


int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // get adjecent list
  unordered_map<int , vector<int>> adj ;
  for(int i = 0 ; i < edges.size() ; i++){
     int u = edges[i].first -1 ;
     int v = edges[i].second -1;
     adj[u].push_back(v);
  }
    
  // get indegree of all nodes
  vector<int> indegree(n) ;
  for(auto i : adj){
      for(auto j : i.second){
          indegree[j]++ ;
      }
  }
  
  //add in queue whose indegree is 0
  queue<int> q ;
  for(int i = 0 ; i < n ; i++){
      if(indegree[i] == 0){
          //pushing i coz we need to push node not indegree of that node
          q.push(i) ;
      }
  }
    
  //apply bfs
  int cnt = 0 ; 
  while(!q.empty()){
      int frontNode = q.front() ;
      q.pop() ;
      
      //we are going to comapre with total vertex so we will get to know that topological order is correct or not
      //if it is correct it means cycle is not present as topological sort is apply only on directed acyclic graph
      cnt++ ;
      
      for(auto i : adj[frontNode]){
          indegree[i]-- ;
          if(indegree[i] == 0){
              q.push(i) ;
          }
      }
  }
    
  if(cnt == n){
      return false ;
  }else{
      return true ;
  }
}