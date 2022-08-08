//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends


class Solution
{
	public:
	void findTopo(int src , vector<int> adj[] ,unordered_map<int , bool > &visited , stack<int> &st){
	    visited[src] = true ;
	    for(auto i : adj[src]){
	        if(!visited[i]){
	            findTopo(i , adj , visited , st) ;
	        }
	    }
	    
	    st.push(src) ;
	}
	
	void findSCC(int s ,unordered_map<int , vector<int> > &transpose  , unordered_map<int , bool > &isreached){
	    isreached[s] = true ;
	    
	    for(auto i : transpose[s]){
	        if(!isreached[i]){
	            findSCC(i , transpose , isreached) ;
	        }
	    }
	}
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<int> adj[])
    {
        int count = 0 ; //ans
        
        //step 1 - find topological order
        unordered_map<int , bool > visited ;
        stack<int> st ;
        
        for(int i = 0 ; i < V ; i++){
            if(!visited[i]){
                findTopo(i , adj , visited , st) ;
            }
        }
        
        
        //step 2 - create transpose of graph
        unordered_map<int , vector<int> > transpose ;
        for(int i = 0 ; i < V ; i++){
            for(auto nbr : adj[i]){
                transpose[nbr].push_back(i) ;
            }
        }
        
        //step 3 - dfs call over topological sort
        unordered_map<int , bool > isreached ; //visited map
        
        while(!st.empty()){
            int top = st.top() ;
            st.pop() ;
            
            if(!isreached[top]){
                findSCC(top , transpose , isreached) ;
                count++ ; 
            }
        }
        
        return count ;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}


// } Driver Code Ends