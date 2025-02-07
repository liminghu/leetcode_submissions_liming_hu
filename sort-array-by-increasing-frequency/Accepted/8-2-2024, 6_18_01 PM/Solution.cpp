// https://leetcode.com/problems/sort-array-by-increasing-frequency

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int, int> frequency; //num, frequency
        int sz = nums.size();
        for(int i=0; i<sz; i++) {
            frequency[nums[i]] = frequency[nums[i]]+1;
        }

        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if(frequency[a]== frequency[b]) {
                return a > b;
            }
            return frequency[a] < frequency[b]; 
            });
        return nums;
    }

    
};