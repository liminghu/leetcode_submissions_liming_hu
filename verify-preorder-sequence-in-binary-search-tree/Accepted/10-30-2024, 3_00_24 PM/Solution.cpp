// https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
        int minLimit = INT_MIN;
        stack<int> st;
        for(int num: preorder) {
            while(!st.empty() && st.top() < num) {
                minLimit = st.top();
                st.pop();
            };
            if(num<=minLimit)
                return false;
            st.push(num);
        }
        return true;
    }
 
};