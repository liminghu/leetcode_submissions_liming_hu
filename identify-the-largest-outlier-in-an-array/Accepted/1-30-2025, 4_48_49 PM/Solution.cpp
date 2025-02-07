// https://leetcode.com/problems/identify-the-largest-outlier-in-an-array

class Solution {
public:
    int getLargestOutlier(vector<int>& nums) { //-1000 <= nums[i] <= 1000
        // exactly n - 2 elements are special numbers. One of the remaining two elements is the sum of these special numbers, and the other is an outlier.
        int ans = INT_MIN;
        int sum = 0;
        unordered_map<int, int> freq;
        for(auto num: nums) {
            sum += num;
            freq[num*2]++;
        }
        for(auto num: nums) {
            int t = sum - num;
            if(freq[t]>=2 || freq[t]==1 && (t!=num*2))
                ans = max(ans, num);
        }
        return ans;
    }
};