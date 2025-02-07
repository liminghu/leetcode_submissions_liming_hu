// https://leetcode.com/problems/trapping-rain-water

//Given n non-negative integers representing an elevation map where the width of each bar is 1, 
//compute how much water it can trap after raining.
class Solution {
public:
    int trap(vector<int>& height) {
        /*
            n == height.length
            1 <= n <= 2 * 104
            0 <= height[i] <= 105
        */
        int ans = 0;
        int sz = height.size();
        if( sz <= 2 )
            return 0;
        
        stack<int> st;
        int i = 0;
        while (i < sz ) {
            while( !st.empty() && height[i] > height[st.top()]) { //have a trap.
               int top = st.top();
               st.pop();
               if(st.empty())
                    break;
                int distance = i - st.top() -1;
                int bounded_height = min(height[i], height[st.top()]) - height[top];
                ans += distance * bounded_height;
            };
            st.push(i);
            i++;
        }
        return ans;
        
    }
};