class Solution{
public:	
	vector<int> kLargest(int arr[], int n, int k) {
	   priority_queue<int , vector<int> , greater<int> > pq ;
       
       for(int i = 0 ; i< k ; i++){
           pq.push(arr[i]) ;
       }
       
       //step 2 - process and comapre remaining 
       for(int i = k ; i < n ; i++){
           //push on condition if they are smaller than top of max heap
           if(arr[i] > pq.top()){
               pq.pop() ;
               pq.push(arr[i]) ;
           }
       }
       
       vector<int> ans ;
       int ele ; 
       for(int i = 0 ; i < k ; i++){
           ele = pq.top() ;
           pq.pop() ;
           ans.push_back(ele) ;
       }
       
       reverse(ans.begin() , ans.end()) ;
       return ans ;
	}

};
