// https://leetcode.com/problems/maximum-width-ramp

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        stack<int> indStack;
        for(int i=0; i<n; i++) {
            if(indStack.empty() || nums[indStack.top()] > nums[i])
                indStack.push(i);
        }
        int maxWidth = 0;
        for(int j=n-1; j>=0; j--) {
            while(!indStack.empty() && nums[indStack.top()]<=nums[j]) {
                maxWidth = max(maxWidth, j-indStack.top());
                indStack.pop();
            }
        }
        return maxWidth;

    }
};