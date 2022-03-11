#include<stack>

bool findRedundantBrackets(string &s)
{
	stack<char> st ;
    for(int i = 0 ; i < s.length() ; i++){
        if((s[i] == '(') || (s[i] == '+') || (s[i] == '-')|| (s[i] == '*') || (s[i] == '/')) {
        	st.push(s[i]);                                                  
        }else{
         //closing bracket or letter
            if(s[i] == ')'){
                bool isRedundant = true ;
                
                while(st.top() != '('){
                    char top = st.top() ;
                    if((top == '+') || (top == '-') || (top == '*') ||(top == '/')){
                        isRedundant = false ;
                    }
                    //for iteration over all stack elemtn untill top != opening bracket
                    st.pop() ;
                }
                //redudant sathi
                if(isRedundant == true){
					return true ;
                }
                //for opning bracket when while condition false 
				st.pop() ;
            }
        }
    }
           
     return false ;
}
