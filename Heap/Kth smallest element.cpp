
class Solution{
    public:
    // arr : given array
    // l : starting index of the array i.e 0
    // r : ending index of the array i.e size-1
    // k : find kth smallest element and return using this function
    int kthSmallest(int arr[], int l, int r, int k) {
        //step 1 - create a maxheap and push first k ele
       priority_queue<int> pq ;
       
       for(int i = 0 ; i< k ; i++){
           pq.push(arr[i]) ;
       }
       
       //step 2 - process and comapre remaining 
       for(int i = k ; i <= r ; i++){
           //push on condition if they are smaller than top of max heap
           if(arr[i] < pq.top()){
               pq.pop() ;
               pq.push(arr[i]) ;
           }
       }
       
       int ans = pq.top() ;
       
       return ans ;
    }
};
