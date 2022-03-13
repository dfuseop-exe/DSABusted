class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        stack<int> st ;
        st.push(-1) ;
        
        vector<int> ans(n) ;
        
        for(int i = 0; i <= n-1 ; i++){
            int curr = a[i] ;
            
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
};