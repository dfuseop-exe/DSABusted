queue<int> modifyQueue(queue<int> q, int k) {
    
    stack<int> s ;

    //step 1 fetch start k elements from queue and push into stack
    for(int i = 0 ; i < k ; i++){
        int element = q.front();
        q.pop();
        s.push(element);
    }
    
    //now step - 2 push stack elements into queue
    //for(int i = 0 ; i < k ; i++)
    
    while(!s.empty()){
        int ele = s.top();
        s.pop();
        q.push(ele);
    }
    
    //step 3

    int rotate = q.size() - k ;
    
    for(int i = 0 ; i < rotate ; i++){
        int ele = q.front() ;
        q.pop();
        q.push(ele);
    }
    
    return q ;
}