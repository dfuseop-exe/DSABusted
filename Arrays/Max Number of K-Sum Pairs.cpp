class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        sort(nums.begin() , nums.end()) ;
        int s = 0 ;
        int e = nums.size() - 1 ;
        int ans = 0 ;
        
        while(s < e){
            if(nums[s] + nums[e] == k){
                nums[s] = 0 ;
                nums[e] = 0 ;
                ans++ ;
                s++ ;
                e-- ;
            }else if(nums[s] + nums[e] > k){
                e-- ;
            }else{
                s++ ;
            }
        }
        
        return ans ;
    }
};