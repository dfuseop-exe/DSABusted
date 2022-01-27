class Solution {
private:
    void solve(string digits , string output ,int index , vector<string> &ans , string mapping[]){
        //base case
        if(index >= digits.length()){
            ans.push_back(output);
            return ;
        }
        
        //when we want '2' -> 2 ;
        int element = digits[index] - '0';
        string value = mapping[element];
        
        //current value[0]  
        for(int i=0 ; i < value.length() ;i++){
            output.push_back(value[i]);
            solve(digits ,output , index+1 , ans , mapping);
            output.pop_back();
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> ans ;
        
        //check
        if(digits.length() == 0){
            return ans;
        }
        
        int index = 0;
        string output ;
        string mapping[10] = {" " , " " , "abc" , "def" , "ghi" , "jkl" , "mno" , "pqrs" , "tuv" , "wxyz"};
        solve(digits , output , index , ans , mapping);
        return ans;
        
    }
};