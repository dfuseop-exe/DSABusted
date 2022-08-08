class Solution{
public:
    int kthLargest(vector<int> &Arr,int N,int K){
        //step 1 - create all combination and sum of all store in vector
        vector<int> ans ;
        
        for(int i = 0 ; i < N ; i++){
            
            int sum = 0 ;
            
            for(int j = i ; j < N ; j++){
                
                sum = sum + Arr[j] ;
                ans.push_back(sum) ;
                
            }
            
        }
        
        int n = ans.size() ;


        //then apply kth largest wala logic
        
        //step 2 - use min heap to get largest sum at top
        priority_queue<int , vector<int> , greater<int> > pq ;
        
        for(int i = 0 ; i < K ; i++){
            pq.push(ans[i]) ;
        }
        
       for(int i = K ; i < n ; i++){
           //push on condition if they are greater than top of max heap
           if(ans[i] > pq.top()){
               pq.pop() ;
               pq.push(ans[i]) ;
           }
       }
        
        return pq.top() ;

    }
};