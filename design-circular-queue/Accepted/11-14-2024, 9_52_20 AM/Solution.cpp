// https://leetcode.com/problems/design-circular-queue

class MyCircularQueue {
public:
    MyCircularQueue(int k) {
        q.resize(k);
        count = 0;
        sz = k;
        headIdx = 0;
    }
    
    bool enQueue(int value) {
        if(isFull())
            return false;
        q[(headIdx+count)%sz] = value;
        count++;
        return true;
    }
    
    bool deQueue() {
        if(isEmpty())
            return false;
        headIdx = (headIdx+1)%sz;
        count--;
        return true;       
    }
    
    int Front() {
        if(isEmpty())
            return -1;
        return q[headIdx];
    }
    
    int Rear() {
        if(isEmpty())
            return -1;
        return q[(headIdx+count-1)%sz];
    }
    
    bool isEmpty() {
        return count == 0;
    }
    
    bool isFull() {
        return count == sz;
    }
private:
    int count;
    int sz;
    int headIdx;
    vector<int> q;
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