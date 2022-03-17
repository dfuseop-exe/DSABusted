class Solution 
{
    private:
    bool know(int A , int B ,vector<vector<int> >& M ){
        if(M[A][B] == 1){
            return true ;
        }else{
            return false ;
        }
    }
    
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
         //step 1 - put all candidate in stack (n)
         
         stack<int> s ;
         
         for(int i = 0 ; i < n ; i++){
             s.push(i);
         }
         
         //step 2 - remove 2 elements
         while(s.size() > 1){
             
             int A = s.top() ;
             s.pop() ;
             
             int B = s.top() ;
             s.pop() ;
             
             if(know(A,B,M)){
                 s.push(B);
             }else{
                 s.push(A);
             }
         }
         
         // step - 3 there is single element in stack that may be Celebrity 
         // So now varify it
        int ans = s.top() ;
         
        //Celebrity knows know one so all zero should be there
        bool rowCheck = false ;
        int zeroCount = 0 ;
         
        for(int i=0; i<n; i++) {
            if(M[ans][i] == 0)
                zeroCount++;
        }
         
         //all zero ?
         if(zeroCount == n){
             rowCheck = true ;
         }
         
         
         //all knows celebrity so all one should be there excepts diagonal
         bool colCheck = false ;
         int oneCount = 0 ;
         
         for(int i = 0 ; i<n ; i++){
             if(M[i][ans] == 1){
                 oneCount++ ;
             } 
         }
         
         
         //all one except diagonal  ?
         if(oneCount == n-1){
             colCheck = true ;
         }
         
         if(rowCheck == true && colCheck == true){
             return ans ;
         }else{
             return -1 ;
         }
    }
};

