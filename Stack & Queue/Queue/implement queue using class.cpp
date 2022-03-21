class Queue {
    int *arr ;
    int size ;
    int front1 ;
    int rear ;
public:
    Queue() {
        // Implement the Constructor
        size = 10001 ;
        arr = new int[size] ;
        front1 = 0 ;
        rear = 0 ;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(rear == front1){
            return true ;
        }else{
            return false ;
        }
    }

    void enqueue(int data) {
        // Implement the enqueue() function
		//queue full condition
        if(rear == size){
            cout<<"Queue is full"<<endl;
        }else{
            arr[rear] = data ;
        	rear++ ;
        }
    }

    int dequeue() {
        // Implement the dequeue() function
        //queue empty condition
        if(front1 == rear){
            return -1 ;
        }else{
            int ans = arr[front1] ;
            arr[front1] = -1 ;
        	front1++ ;
            if(front1 == rear){
                front1 = 0 ;
                rear = 0 ;
            }
            return ans ;
        }
    }

    int front() {
        // Implement the front() function
        if(front1 == rear){
            return -1 ;
        }else{
            return arr[front1] ;
        }
    }
};