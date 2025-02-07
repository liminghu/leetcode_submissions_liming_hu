// https://leetcode.com/problems/maximum-number-of-distinct-elements-after-operations

class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        //Add an integer in the range [-k, k] to the element.
        int ans = 0;
        sort(nums.begin(), nums.end());
        int last = INT_MIN;
        for(int i=0; i<nums.size(); i++) {
            int mn = nums[i]-k;
            int mx = nums[i]+k;
            if(last < mn) {
                last = mn;
                ans++;
            } else if( last < mx) {
                last = last+1;
                ans++;
            }
        }
        return ans;
    }
};