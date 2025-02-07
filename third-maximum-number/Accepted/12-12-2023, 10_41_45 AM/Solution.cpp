// https://leetcode.com/problems/third-maximum-number

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set<int> max_list;
        for(size_t i=0; i<nums.size(); i++) {
            max_list.insert(nums[i]);
            if(max_list.size()>3) 
                max_list.erase(max_list.begin()); //remove the smallest.
        }

        if(max_list.size()==3)
            return *max_list.begin(); //the smallest
        else
            return *max_list.rbegin();

    }
};