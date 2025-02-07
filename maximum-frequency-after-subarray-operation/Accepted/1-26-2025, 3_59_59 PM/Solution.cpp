// https://leetcode.com/problems/maximum-frequency-after-subarray-operation

class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {//1 <= nums[i] <= 50
        int n = nums.size();
        vector<int> freq(51, 0);
        int freq_k = 0;
        int res = 0;
        for(int i=0; i<n; i++) {
            freq[ nums[i] ] = max(freq[ nums[i] ], freq_k )+1;
            res += (nums[i]==k);
            freq_k += (nums[i]==k);
            res = max(res, freq[ nums[i] ]);
        }
        return res;
    }
};