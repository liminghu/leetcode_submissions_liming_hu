// https://leetcode.com/problems/maximal-rectangle

/*
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
rows == matrix.length
cols == matrix[i].length
1 <= row, cols <= 200
matrix[i][j] is '0' or '1'.
*/
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty())
            return 0;
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> hist(n,0);
        int ans = 0;
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(matrix[i][j] == '1')
                    hist[j] += 1;
                else
                    hist[j] = 0;
            }
            ans = max(ans, largestRectangle(hist));
        }
        return ans;        
    }
    int largestRectangle(vector<int> hist) {
        hist.insert(hist.begin(), 0);
        hist.push_back(0);
        int n = hist.size();
        stack<int> st;
        int ret = 0;
        for(int i=0; i<hist.size(); i++) {
            while(!st.empty() && hist[st.top()] > hist[i]) {
                int h = hist[st.top()];
                st.pop();
                int area = h*(i-st.top()-1);
                ret = max(ret,area);
            }
            st.push(i); // hist[st.top()] <= hist[i]
        }
        return ret;
    }
};