// https://leetcode.com/problems/maximum-frequency-stack

class FreqStack {
    unordered_map<int, int> freq;  //Hash map freq will count the frequence of elements
    unordered_map<int, stack<int>> m;   //freq, vector<int>
    int maxFreq = 0;
public:
    FreqStack() {     
    }
    
    void push(int val) {
        freq[val]++;
        maxFreq = max(maxFreq, freq[val]);
        m[ freq[val] ].push(val);  //If element x has n frequence, we will push x n times in m[1], m[2] .. m[n]
    }
    
    int pop() {
        int x = m[maxFreq].top();
        m[maxFreq].pop();
        if(m[ freq[x] ].size() == 0) {
            freq[x]--;
            maxFreq--;
        }
        return x;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */