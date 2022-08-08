string longestCommonPrefix(vector<string> &arr, int n)
{
    string ans = "" ;
    //for first string process one character and check 
    for(int i = 0 ; i < arr[0].size() ; i++){
        char ch = arr[0][i] ;
        
        //take flag to if now same then indicate to break the loop
        bool isMatched = true ;
        
        for(int j = 1 ; j < arr.size() ; j++){
            //first string jada badi hogi current string se to bhi break  karo
            if(arr[j].size() < i || ch != arr[j][i]){
                isMatched = false ;
            }
        }
        
        
        if(isMatched == true){
            ans.push_back(ch) ;
        }else{
            break ;
        }
    }
    
    return ans ;
}

