// https://leetcode.com/problems/longest-square-streak-in-an-array

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int ret = 0;
        unordered_set<int> uniqueNums(nums.begin(), nums.end());
        for(int startNum: nums) {
            int currentStreak = 0;
            long long cur = startNum;
            while(uniqueNums.find((int)cur)!=uniqueNums.end()) {
                currentStreak++;
                if(cur*cur>1e5)
                    break;
                    cur *= cur;
            }
            ret = max(ret, currentStreak);                          
        }
        return ret<2? -1: ret;
    }
};