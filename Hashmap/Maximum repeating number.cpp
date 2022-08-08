class Solution{
public:	
	// Returns maximum repeating element in arr[0..n-1].
	// The array elements are in range from 0 to k-1
	int maxRepeating(int *arr, int n, int k) {
	    unordered_map<int,int> count ;
	    
	    int maxRep = 0 ;
	    int ansRep = INT_MAX ;
	    
	    for(int i = 0 ; i < n ; i++){
	        count[arr[i]] ++ ;
	        maxRep = max(maxRep ,count[arr[i]]) ;
	    }
	    
	    for(int i = 0 ; i < n ; i++){
	        if(count[arr[i]] == maxRep){
	            
	            if(arr[i] < ansRep){
	                ansRep = arr[i] ;
	            }
	        }
	    }
	    
	    return ansRep ;
	}

};