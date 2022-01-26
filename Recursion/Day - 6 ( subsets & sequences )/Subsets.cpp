class Solution {
private:
                             //reference coz here we copy output data in ans vector 
    void solve(vector<int> nums , vector<int> output , int index , vector<vector<int>>& ans){
        //base case
        if(index >= nums.size()){
            //last stage so copy output vector in ans
            ans.push_back(output);
            return ;
        }
        
        //exclude Call
        solve(nums , output , index+1 , ans);
        
        //include Call
        int element = nums[index];
        output.push_back(element);
        solve(nums , output , index+1 , ans);
    }

public:
    vector<vector<int>> subsets(vector<int>& nums) {
        //for storing ans ie- output vector
        vector<vector<int>> ans ;
        int index = 0 ;
        vector<int> output ;
        
        solve(nums , output , index , ans);
        return ans ;
    }
};