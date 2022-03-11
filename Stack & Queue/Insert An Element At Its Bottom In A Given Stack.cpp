void solve(stack<int>& myStack, int x){
    //base case
    if(myStack.empty()){
        myStack.push(x);
        return ;
    }
    
    //put top as side 
    int num = myStack.top();
    myStack.pop() ;
    
    solve(myStack,x);
    
    //now insert it again 
    myStack.push(num);

}

stack<int> pushAtBottom(stack<int>& myStack, int x) 
{
 	solve(myStack , x);
    return myStack ;
}
