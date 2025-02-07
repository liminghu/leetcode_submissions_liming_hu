// https://leetcode.com/problems/valid-triangle-number

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ret = 0;
        for(int right = n-1; right>=2; right--) {
            int left = 0;
            int mid = right-1;
            while(left<mid) {
                if(nums[left]+nums[mid] > nums[right]) {
                    ret += (mid-left);
                    mid--;
                } else {
                    left++;
                }
            }
        }
        return ret;
    }
};