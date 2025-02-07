// https://leetcode.com/problems/two-sum

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hash_table;

        for (int i = 0; i < nums.size(); i++) {
            int num_complement = target - nums[i];
            if (hash_table.count(num_complement))
                return { hash_table[num_complement], i };

            hash_table[nums[i]] = i;
        }

        return {};
    }
};