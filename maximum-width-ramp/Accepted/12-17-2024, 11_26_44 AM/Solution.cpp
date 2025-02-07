// https://leetcode.com/problems/maximum-width-ramp

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int> ind(n);
        for(int i=0; i<n; i++)
            ind[i] = i;
        sort(ind.begin(), ind.end(), [&](int i, int j) {
            return nums[i]!=nums[j]? nums[i]<nums[j]:i<j;
         });
        int minInd = n;
        int maxWidth = 0;
        for(int i=0; i<n; i++) {
            maxWidth=max(maxWidth, ind[i]-minInd);
            minInd = min(minInd, ind[i]);
        }
        return maxWidth;
    }
    int maxWidthRamp1(vector<int>& nums) {
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