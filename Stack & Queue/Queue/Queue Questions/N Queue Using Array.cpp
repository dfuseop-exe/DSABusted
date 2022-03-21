class NQueue{
private:
    int size ;
    int qn ;
    int *arr ;
    int *next ;
    int *front ;
    int *rear ;
    int freespot ;
public:
    NQueue(int n, int s){
        
        // Initialize variables 
        size = s ;
        qn = n ;
        freespot = 0 ;
        
        //define arrays 
        arr = new int[size] ;
        next = new int[size] ;
        //assign next free spot value to next array
        for(int i = 0 ; i < size ; i++){
            next[i] = i+1 ;
        }
        //last index should be -1 coz there is no free spot is available 
        next[size-1] = -1 ;
        
        // initialized front and rear arrays 
        front = new int[qn] ;
        rear = new int[qn] ;
        //assign initially -1 value to front and rear 
        for(int i = 0 ; i < qn ; i++){
            front[i] = -1 ;
            rear[i] = -1 ;
        }
    }

    // Enqueues 'X' into the Mth queue. Returns true if it gets pushed into the queue, and false otherwise.
    bool enqueue(int x, int m){
        
        //step -1 : check for overflow condition
        if(freespot == -1){
            return false ;
        }
        
        //step -2 : check for available position to insert a element 
        int index = freespot ;
        
        //step - 3 : update freespot as we use it
        freespot = next[index] ;
        
        //step - 4 : push element into queue check for first element or not
        if(front[m-1] == -1){
            front[m-1] = index ;
        }else{
            //link previous element of mth queue to current index 
            next[rear[m-1]] = index ;
        }
        
        //step -5 : update next of index coz this position is used 
        next[index] = -1 ;
        
        //step -6 : update rear coz we are adding element at back
        rear[m-1] = index ;
        
        //step - 7 : pushed element
        arr[index] = x ;
        
        return true ;
    }

    // Dequeues top element from Mth queue. Returns -1 if the queue is empty, otherwise returns the popped element.
    int dequeue(int m){
        //check queue empty condition
        if(front[m-1] == -1){
            return -1 ;
        }
        
        //search index to pop
        int index = front[m-1] ;
        
        //increment front value to next element of mth queue
        front[m-1] = next[index];
        
        //manage freespot
        next[index] = freespot ;
        freespot = index ;
        
        return arr[index] ;
    }
};