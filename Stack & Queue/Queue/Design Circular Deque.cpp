class MyCircularDeque {
private:
    deque<int> d;
    int tsize;
public:
    MyCircularDeque(int k) {
        tsize=k;
    }
    
    bool insertFront(int value) {
        if(!isFull())
        {
            d.push_front(value);

            return true;
        }
        return false;
    }
    
    bool insertLast(int value) {
        if(!isFull())
        {
            d.push_back(value);

            return true;
        }
        return false;
    }
    
    bool deleteFront() {
        if(!isEmpty())
        {
            d.pop_front();
            return true;
        }
        return false;
    }
    
    bool deleteLast() {
        if(!isEmpty()){
            d.pop_back();
            return true;
        }
        return false;
    }
    
    int getFront() {
        if(isEmpty()){return -1;}      
            return d.front();
    }
    
    int getRear() {
        if(isEmpty()){return -1;} 
            return d.back();
    }
    
    bool isEmpty() {
        return (d.size()==0);
    }
    
    bool isFull() {
        return (d.size()==tsize);
    }
};

/**
 * Your MyCircularDeque object will be instantiated and called as such:
 * MyCircularDeque* obj = new MyCircularDeque(k);
 * bool param_1 = obj->insertFront(value);
 * bool param_2 = obj->insertLast(value);
 * bool param_3 = obj->deleteFront();
 * bool param_4 = obj->deleteLast();
 * int param_5 = obj->getFront();
 * int param_6 = obj->getRear();
 * bool param_7 = obj->isEmpty();
 * bool param_8 = obj->isFull();
 */