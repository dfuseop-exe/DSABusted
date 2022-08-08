//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    void dfs(int node , int parent , vector<int> adj[] ,vector<int> &discoveryTime ,vector<int> &lowTime ,
    unordered_map<int , bool> &vis , set<int> &ap , int &timer){
                 
            //dfs flow
            vis[node] = true ;
            discoveryTime[node] = lowTime[node] = timer++ ;
            int child = 0 ;
            
            for(auto i : adj[node]){
                if(i == parent){
                    continue ; //ignore
                }
                
                if(!vis[i]){
                    
                    child++ ;
                    
                    //dfs call
                    dfs(i , node ,adj , discoveryTime ,lowTime , vis , ap , timer) ;
                    
                    //while returning make sure to update lowTime of node
                    lowTime[node] = min(lowTime[node] , lowTime[i]) ;
                    
                    //also check for condition of articulationPoint
                    if(discoveryTime[node] <= lowTime[i] && parent != -1){
                        ap.insert(node) ;
                    }  

                }else {
                    //back edge case
                    lowTime[node] = min(lowTime[node] ,discoveryTime[i]) ;
                }
                
            }
            
            //handle special case of parent -1
            if(parent == -1 && child > 1){
               ap.insert(node) ;
            }
            
    }
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        set<int> ap ;
        vector<int> discoveryTime(V,-1) ;
        vector<int> lowTime(V,-1) ;
        unordered_map<int , bool> vis(V) ;
        int parent = -1 ;
        int timer = 0 ;
        
        //dfs
        for(int i = 0 ; i < V ; i++){
            if(!vis[i]){
                dfs(i , parent , adj , discoveryTime ,lowTime , vis , ap , timer) ;
            }
        }
        
        
        vector<int> ans ;
        
        //if no node is AP then send -1 
        if(ap.size() == 0){
            ans.push_back(-1) ;
            return ans ;
        }
    
        
        //as output format does not allow duplicate node So here set is used nd then store in vector to return
        while(ap.size() > 0){
            auto top = *(ap.begin()) ;
            ans.push_back(top) ;
            ap.erase(ap.begin()) ; ;
        }
        
        
        sort(ans.begin(),ans.end()) ;
        return ans ;
    }
};

//{ Driver Code Starts.

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		vector<int> ans = obj.articulationPoints(V, adj);
		for(auto i: ans)cout << i << " ";
		cout << "\n";
	}
	return 0;
}
// } Driver Code Ends