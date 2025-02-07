// https://leetcode.com/problems/find-the-xor-of-numbers-which-appear-twice

class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int, int> nums_dict;

        for(int i=0; i<nums.size(); i++) {
            nums_dict[nums[i]]++;
        }

        int res = 0;

        for(const auto &kv : nums_dict)  {
            if(kv.second == 2) 
                res ^= kv.first;
        };

        return res;
    }
};