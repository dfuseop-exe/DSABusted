class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    //step 1 - create a maxheap and push first k ele
       priority_queue<int , vector<int> , greater<int> > pq ;
       
       for(int i = 0 ; i< k ; i++){
           pq.push(nums[i]) ;
       }
       
       //step 2 - process and comapre remaining 
       for(int i = k ; i < nums.size() ; i++){
           //push on condition if they are smaller than top of max heap
           if(nums[i] > pq.top()){
               pq.pop() ;
               pq.push(nums[i]) ;
           }
       }
       
       int ans = pq.top() ;
       
       return ans ;
    }
};