// https://leetcode.com/problems/maximum-frequency-stack

class FreqStack {
    unordered_map<int, int> freqMap;  //Hash map freq will count the frequence of elements
    unordered_map<int, stack<int>> setMap;   //freq, vector<int>
    int maxFreq = 0;
public:
    FreqStack() {     
    }
    
    void push(int val) {
        int freq = freqMap[val];
        freqMap[val] = freq+1;
        maxFreq = max(maxFreq, freq+1);
        //cout << "push maxFreq: " <<maxFreq << endl;
        setMap[ freqMap[val] ].push(val);  //If element x has n frequence, we will push x n times in m[1], m[2] .. m[n]
    }
    
    int pop() {
        //cout << "pop maxFreq: " <<maxFreq << endl;
        int val = setMap[maxFreq].top();
        setMap[maxFreq].pop();
        freqMap[val]--;
        if(setMap[ maxFreq ].size() == 0 ) 
            maxFreq--;
        //cout << "pop val: " <<val << endl;
        return val;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */