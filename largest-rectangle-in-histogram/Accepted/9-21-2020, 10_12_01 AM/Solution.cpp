// https://leetcode.com/problems/largest-rectangle-in-histogram

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //https://www.youtube.com/watch?v=TH9UaZ6JGcA&t=182s
        //increasing stack.
        //less, calculate.
        
        if( heights.size() == 0) return 0;
        if(heights.size()==1) return heights[0];
        
        int ans=0;
        heights.push_back(0);
        stack<int> mono_idx;
        
        
        for(int i=0; i<heights.size(); i++) {
            while(!mono_idx.empty() && heights[mono_idx.top()]>heights[i]) {
                //start decreasing.
                int h = heights[mono_idx.top()]; mono_idx.pop();
                int l = mono_idx.empty()? -1: mono_idx.top(); //when empty i-(-1)-1 = i.
                ans = max(ans, h*(i-l-1)); //does not count i. 
            }
            mono_idx.push(i);
        }
        return ans;
        
    }
};