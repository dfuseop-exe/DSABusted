#include<stack>

int findMinimumCost(string str) {

	//ans is not possible
    if(str.length() % 2 == 1){
        return - 1;
    } 
    
    stack<char> st ;
    
    for(int i= 0 ; i<str.length();i++){
        char ch = str[i] ;
        
        if(ch == '{'){
            st.push(ch);
        }else{
            //closing 
            //now check top ele whether it is open if true then remove so it remove valid brace
        	if( !st.empty() && st.top() == '{' ){
                st.pop();
            }else{
                st.push(ch);
            }
        }
        //now stack contain all invalid brackets
       	//count open nd close brackets   
    }
    
    int open = 0 ;
        int close = 0 ;
        
        while(!st.empty()){
            if(st.top() == '{'){
                open++ ;
            }else{
                close++ ;
            }
            
            st.pop();
        }
        
    int ans = ((open + 1) / 2) + ((close + 1) / 2 ); 
    return ans ; 
}