char* reverse(char *S, int len)
{
    stack<char> s ;
    
    for(int i=0 ; i<len ; i++){
        char ch = S[i] ;
        s.push(ch);
    }
    
    char* ans = new char[len];
    
    int i = 0 ;
    while(!s.empty()){
        char ch = s.top() ;
        ans[i]= ch;
        i++;
        s.pop();
    }
    
    return ans ;
    
}