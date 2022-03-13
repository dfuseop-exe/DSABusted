#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n)
{
    stack<int> st ;
    st.push(-1) ;
    
    vector<int> ans(n) ;
    
    for(int i = n-1 ; i >= 0; i--){
        int curr = arr[i] ;
        
        //if greater loop exicutes
        while(st.top() >= curr){
            st.pop() ;
        }
        
        //now ans is stack ka top
        ans[i] = st.top() ;
        //push current element 
        st.push(curr) ;
    }
    
    return ans ;
}