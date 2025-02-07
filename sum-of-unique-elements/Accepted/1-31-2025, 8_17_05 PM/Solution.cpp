// https://leetcode.com/problems/sum-of-unique-elements

class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        unordered_map<int,int> count;
        for(int num: nums)
            count[num]++;
        int sum = 0;
        for(auto item: count) {
            if(item.second == 1)
                sum+= item.first;
        };
        return sum;
    }
};