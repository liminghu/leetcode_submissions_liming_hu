// https://leetcode.com/problems/min-stack

/*
Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

MinStack() initializes the stack object.
void push(int val) pushes the element val onto the stack.
void pop() removes the element on the top of the stack.
int top() gets the top element of the stack.
int getMin() retrieves the minimum element in the stack.
You must implement a solution with O(1) time complexity for each function.
-231 <= val <= 231 - 1
Methods pop, top and getMin operations will always be called on non-empty stacks.
At most 3 * 104 calls will be made to push, pop, top, and getMin.
*/
class MinStack {
private:
    stack<pair<int,int>> st;
public:
    MinStack() {//initializes the stack object.
    }
    
    void push(int val) { //pushes the element val onto the stack.
        if(st.empty()) {
            st.push({val,val});
            return;
        }
        int currentMin = st.top().second;
        st.push({val, min(val, currentMin)});
    }
    
    void pop() { //removes the element on the top of the stack.
        st.pop();
    }
    
    int top() { //gets the top element of the stack.
        return st.top().first;
    }
    
    int getMin() { //retrieves the minimum element in the stack.
        return st.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */