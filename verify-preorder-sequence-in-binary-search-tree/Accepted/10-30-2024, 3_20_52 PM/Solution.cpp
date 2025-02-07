// https://leetcode.com/problems/verify-preorder-sequence-in-binary-search-tree

class Solution {
public:
    bool verifyPreorder(vector<int>& preorder) {
    
        return dfs(preorder, 0, preorder.size()-1);
    /*    int minLimit = INT_MIN;
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
        return true;*/
    }
    bool dfs(vector<int>& preorder, int start, int end) {
        if(start==end)
            return true;
        if(start>end)
            return true;
        int root = preorder[start];
        int i = start+1;
        while(i<=end && preorder[i] < root)
            i++;
        //i: right
        for(int j=i; j<=end; j++) {
            if(preorder[j]<root)
                return false;
        }
        return dfs(preorder, start+1,i-1) && dfs(preorder, i, end);
    }
 
};