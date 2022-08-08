//striver 

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int num1 = -1 ;
        int num2 = -1 ;
        int cnt1 = 0 ;
        int cnt2 = 0 ;
        
        int len = nums.size() ;
        
        
        for(int i = 0 ; i < len ; i++){
            if(nums[i] == num1){
                cnt1++ ;
            }else if(nums[i] == num2){
                cnt2++ ;
            }else if(cnt1 == 0){
                num1 = nums[i] ;
                cnt1 = 1 ;
            }else if(cnt2 == 0){
                num2 = nums[i] ;
                cnt2 = 1 ;
            }else{
                cnt1-- ;
                cnt2-- ;
            }
        }
        
        cnt1 = 0 ;
        cnt2 = 0 ;
        
        vector<int> ans ;
        
        for(int i = 0 ; i < len ; i++){
            if(nums[i] == num1){
                cnt1++ ;
            }else if(nums[i] == num2){
                cnt2++ ;
            }
        }
        
        if((cnt1 > len / 3)){
            ans.push_back(num1) ;
        }
        
        if((cnt2 > len / 3)){
            ans.push_back(num2) ;
        }
        
        return ans ;
    }
};