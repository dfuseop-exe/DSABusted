class Solution
{
	public:
	void topologySort(int src , vector<int> &ans ,vector<int> adj[] , unordered_map<int , bool> &visited , stack<int> &st ){
	    
        //DFS
	    visited[src] = true ;
	    
	    for(auto i : adj[src]){
	        if(!visited[i]){
	            topologySort(i , ans , adj , visited , st ) ;
	        }
	    }
	    
	    //push into stack 
	    st.push(src) ;
	}
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{   
        //create DS
	    stack<int> st ;
	    unordered_map<int , bool> visited ;
	    vector<int> ans ;
	    
        //step-2 iterate over vertices
	    for(int i = 0 ; i < V ; i++){
	        if(!visited[i]){
                //and process
	            topologySort(i , ans , adj , visited , st ) ;
	        }
	    }
	    
        //copy all stack elements into vector
	    while(!st.empty()){
	        ans.push_back(st.top()) ;
	        st.pop();
	    }
	    
	    return ans ;
	}
};