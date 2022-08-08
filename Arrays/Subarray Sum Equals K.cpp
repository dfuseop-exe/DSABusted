class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int , int> mpp ;
        vector<int> prefix ;
        
        int ans = 0 ;
        int sum = 0 ;
        
        for(int i = 0 ; i < nums.size() ; i++){
            //step - 1 - create prefix with sum
            sum += nums[i] ;
            
            prefix.push_back(sum) ;
            
            //step 2 - check is prefix is your k ?
            if(prefix[i] == k){
                ans++ ;
            }
            
            //step 3 - if no get ignored as we add it in prefix so it will always get detected by                                following  , it means ki nums[i] is == k so that 
            ans += mpp[sum-k] ;
            
            //step 4 - add new entry 
            mpp[sum]++ ;
        }
        
        return ans ;
    }
};