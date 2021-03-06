void reverse(queue<int>& q){
    //base condition
    if(q.empty()){
        return ;
    }
    
    int element = q.front();
    q.pop();
    
    reverse(q);
    
    q.push(element);
}

//Function to reverse the queue.
queue<int> rev(queue<int> q)
{
    reverse(q);
    return q ;
}