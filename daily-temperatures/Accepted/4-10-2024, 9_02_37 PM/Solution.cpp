// https://leetcode.com/problems/daily-temperatures

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(),0);
        stack<int> m_stack; // the bottom is the maximum. with index. monomic decreasing.

        if (temperatures.size() == 0)
            return res;

        for (int i=0; i<temperatures.size(); i++) {
            if (m_stack.empty()) {
                m_stack.push(i);
            } else {
                while(!m_stack.empty() && temperatures[i] > temperatures[m_stack.top()] ) {
                    res[m_stack.top()] =  i - m_stack.top();
                    m_stack.pop();
                };
            
                m_stack.push(i);
            }
        }

        return res;

    }
};