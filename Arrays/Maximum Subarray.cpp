class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN ;
        int sum = 0 ;
        
        for(auto i : nums){
            sum += i ;
            
            maxSum = max(maxSum , sum) ;
            
            //coz negative values can result negative sum so we need to reset sum value so that we will get new sum value
            if(sum < 0){
                sum = 0 ;
            }
        }
        
        return maxSum ;
    }
};

