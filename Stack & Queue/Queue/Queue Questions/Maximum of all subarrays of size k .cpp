class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector <int> max_of_subarrays(int *arr, int n, int k)
    {
        deque<long long>maxi(k) ;

        
        //addition of first k size window
        for(int i = 0 ; i < k ; i++){
            
            while(!maxi.empty() && arr[maxi.back()] <= arr[i])
                maxi.pop_back();
            

            
            maxi.push_back(i);

            
        }
        
        //remaining sari window ko check kro
        vector<int> ans ;
        for(int i = k ; i < n ; i++){
            ans.push_back(arr[maxi.front()]);
            
            //next window
            //removal range check
            while(!maxi.empty() && i - maxi.front() >= k){
                maxi.pop_front();
            }
            

            //addition of new element
            while(!maxi.empty() && arr[maxi.back()] <= arr[i])
                maxi.pop_back();

            
            maxi.push_back(i);
  
        }
        
        //make sure to consider last window
        ans.push_back(arr[maxi.front()]);
        return ans ;
        }
};