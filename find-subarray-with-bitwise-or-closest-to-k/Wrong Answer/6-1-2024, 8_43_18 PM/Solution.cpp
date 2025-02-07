// https://leetcode.com/problems/find-subarray-with-bitwise-or-closest-to-k

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) { //1 <= nums[i] <= 109 ; 1 <= k <= 109
        int ans = 0;

        if(nums.size()==1)
            return abs(k-nums[0]);

        vector<int> bitwiseAndI;
        bitwiseAndI.push_back(nums[0]);
        int temp=0;
        for(int i=1; i<nums.size(); i++) {
            temp = bitwiseAndI[i-1] & nums[i];
            bitwiseAndI.push_back(temp);
        };

        
        //int s=1;
        //int e = nums.size()-1;
        int bitwiseAnds = 0;
        int bitwiseAnde = 0;
        int bitwisese = 0;
        int minDiff = k;
        for(int s=1; s<nums.size()-1; s++) {
            for(int e=s+1; e<nums.size(); e++) {
                //bitwiseAnd i to j = bitwiseAndj & bitwiseAnd(i-1);
                bitwiseAnds = bitwiseAndI[s-1];
                bitwiseAnde = bitwiseAndI[e];
                bitwisese =   bitwiseAnde & bitwiseAnds;
                if(abs(bitwisese-k)<minDiff)
                    minDiff = abs(bitwisese-k);
            }
        };

        return minDiff;
        
    }
};