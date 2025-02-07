// https://leetcode.com/problems/identify-the-largest-outlier-in-an-array

class Solution {
public:
    int getLargestOutlier(vector<int>& nums) {
        unordered_map<int, int> freq;
        int sum = 0; 
        int res = INT_MIN;
        for(auto num: nums) {
            sum+= num;
            freq[num]++;
        };
        for(auto num: nums) {
            int outlier = sum - num - num;
            if(freq[outlier] >(outlier==num))
                res = max(res, outlier);
        };
        return res;
    }
};