void solve(stack<int> &stack , int n){
	//base condition
    if( stack.empty() || stack.top() < n){
        stack.push(n);
        return ;
    }
    
    int num = stack.top() ;
    stack.pop() ;
    
    solve(stack , n);
    
    //side la kelele element [greater than n element] again insert 
    stack.push(num);
}
void sortStack(stack<int> &stack)
{
	if(stack.empty()){
        return ;
    }
    
    int num = stack.top() ;
    stack.pop() ;
    
    sortStack(stack);
    solve(stack , num);
}