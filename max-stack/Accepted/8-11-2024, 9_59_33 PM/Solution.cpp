// https://leetcode.com/problems/max-stack

/*
Design a max stack data structure that supports the stack operations and supports finding 
the stack's maximum element.

Implement the MaxStack class:

MaxStack() Initializes the stack object.
void push(int x) Pushes element x onto the stack.
int pop() Removes the element on top of the stack and returns it.
int top() Gets the element on the top of the stack without removing it.
int peekMax() Retrieves the maximum element in the stack without removing it.
int popMax() Retrieves the maximum element in the stack and removes it. If there is more than 
one maximum element, only remove the top-most one.
You must come up with a solution that supports O(1) for each top call and O(logn) for each other call.
*/
class MaxStack {
private:
    priority_queue<pair<int, int>> pq_max; //max priority queue.
    stack<pair<int,int>> st;
    unordered_set<int> removed;
    int cnt;
public:
    MaxStack() {
        /*  -107 <= x <= 107
            At most 105 calls will be made to push, pop, top, peekMax, and popMax.
            There will be at least one element in the stack when pop, top, peekMax, or popMax is called.
        */
        cnt = 0; //id
    }
    
    void push(int x) {
        pq_max.push({x,cnt});
        st.push({x,cnt});
        cnt++;
    }
    
    int pop() {
        /*we first check the ID of its top element, if is 
        turns out to be an ID in removed, that is, it was removed previously, 
        we need to remove the current top element until its ID is not in 
        removed to make sure the top still exists*/
        while(removed.count(st.top().second)) { //check id.
            st.pop();
        }
        const pair<int,int> p = st.top();
        st.pop();
        removed.insert(p.second);
        return p.first;
    }
    
    int top() {
        while(removed.count(st.top().second)) {
            st.pop();
        }
        return st.top().first;     
    }
    
    int peekMax() {
        while(removed.count(pq_max.top().second)) {
            pq_max.pop();
        }
        return pq_max.top().first;
        
    }
    
    int popMax() {
        while(removed.count(pq_max.top().second)) {
            pq_max.pop();
        }
        const pair<int,int> p = pq_max.top();
        pq_max.pop();
        removed.insert(p.second);
        return p.first;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */