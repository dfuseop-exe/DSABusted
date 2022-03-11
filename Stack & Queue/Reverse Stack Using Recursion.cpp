void insertAtBottom(stack<int> &stack , int n){
    //base case
    if(stack.empty()){
        stack.push(n);
        return ;
    }
    
    int num = stack.top();
    stack.pop() ;
    
    insertAtBottom(stack,n);
    
    stack.push(num);
}

void solve(stack<int> &stack){
    //base case
    if(stack.empty()){
        return ;
    }
    
    int num = stack.top();
    stack.pop();
    
    solve(stack);
    
    //botom insert coz we are reversing data
    insertAtBottom(stack , num);
}

void reverseStack(stack<int> &stack) {
    solve(stack);
}