class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st ;
        
        //for iterating over string 
        for(int i=0 ; i< s.length() ; i++){
            //if opening push into stack
            //if closing check top nd pop
            
            char ch = s[i];
            
            //opening
            if((ch == '(') || (ch == '{') || (ch == '[')){
                st.push(ch);
            }else{
                //closing ans Not empty 
                //nd stack is empty nd if we trying to access top it causes error  
                if(!st.empty()){  
                    if(( (st.top() == '(')  && ( s[i] == ')') )
                      || ( (st.top() == '{')  && ( s[i] == '}') )
                      || ( (st.top() == '[')  && ( s[i] == ']') ) ){
                        st.pop();
                    }else{
                        //mismatched parantheses
                        return false ;
                    }
                }else{
                    //stack has no  more element 
                    return false ;
                }
            }
        }
        
        if(st.empty()){
            return true ;
        }else{
            return false ;
        }
    }
};