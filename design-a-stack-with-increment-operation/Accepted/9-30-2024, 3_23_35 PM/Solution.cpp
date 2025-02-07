// https://leetcode.com/problems/design-a-stack-with-increment-operation

/*
Design a stack that supports increment operations on its elements.
Implement the CustomStack class:
CustomStack(int maxSize) Initializes the object with maxSize which is the maximum number of elements in the stack.
void push(int x) Adds x to the top of the stack if the stack has not reached the maxSize.
int pop() Pops and returns the top of the stack or -1 if the stack is empty.
void inc(int k, int val) Increments the bottom k elements of the stack by val. If there are less than k elements in the stack, increment all the elements in the stack.
Constraints:

1 <= maxSize, x, k <= 1000
0 <= val <= 100
At most 1000 calls will be made to each method of increment, push and pop each separately.

*/
class CustomStack {
private:
    int maxSize_;
    vector<int> st_;
    int size;

public:
    CustomStack(int maxSize) { //Initializes the object with maxSize which is the maximum number of elements in the stack.
        maxSize_ = maxSize;
        st_.resize(maxSize_);
        size = 0;
    }
    
    void push(int x) { //Adds x to the top of the stack if the stack has not reached the maxSize.
        if(size < maxSize_) {
            st_[size] = x;
            size++;
        }     
    }
    
    int pop() {
        int t = -1;
        if(size != 0) {
            size--;
            t = st_[size];
        };
        return t;
    }
    
    void increment(int k, int val) { //Increments the bottom k elements of the stack by val. If there are less than k elements in the stack, increment all the elements in the stack.
        for(int i=0; i<min(size,k); i++) {
            st_[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */