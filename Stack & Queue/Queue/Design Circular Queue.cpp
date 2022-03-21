class MyCircularQueue {
private:
    queue<int> q;
    int tsize;
public:
    MyCircularQueue(int k) {
        tsize=k;

    }

    bool enQueue(int value) {

        if(!isFull())
        {
            q.push(value);

            return true;
        }
        return false;

    }

    bool deQueue() {

        if(!isEmpty())
        {
            q.pop();

            return true;
        }

        return false;
    }

    int Front() {
            if(q.size()==0){return -1;}      
            return q.front();

    }

    int Rear() {

            if(q.size()==0){return -1;} 
            return q.back();


    }

    bool isEmpty() {

        return (q.size()==0);

    }

    bool isFull() {

        return (q.size()==tsize);

    }
};
/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */