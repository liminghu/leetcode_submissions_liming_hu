// https://leetcode.com/problems/shuffle-the-array

class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        //[x1,x2,...,xn,y1,y2,...,yn].
        //[x1,y1,x2,y2,...,xn,yn].
        vector<int> ans(2*n, 0);
        int j = 0;
        for(int i=0; i<n; i++) {
            ans[j] = nums[i];
            ans[j+1]= nums[i+n];
            j+=2;
        }
        return ans;

    }
};