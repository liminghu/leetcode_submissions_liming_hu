// https://leetcode.com/problems/sort-the-jumbled-numbers

/*
You are given a 0-indexed integer array mapping which represents the mapping rule of a shuffled decimal system. 
mapping[i] = j means digit i should be mapped to digit j in this system.
The mapped value of an integer is the new integer obtained by replacing each occurrence of digit i in the integer 
with mapping[i] for all 0 <= i <= 9.

You are also given another integer array nums. Return the array nums sorted in non-decreasing order based 
on the mapped values of its elements.

Notes:
Elements with the same mapped values should appear in the same relative order as in the input.
The elements of nums should only be sorted based on their mapped values and not be replaced by them.
*/
class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        /*
            mapping.length == 10
            0 <= mapping[i] <= 9
            All the values of mapping[i] are unique.
            1 <= nums.length <= 3 * 104
            0 <= nums[i] < 109
        */
        int sz = nums.size();
        vector<pair<int, int>> mapped_nums(sz); //pair<int, int>: mapped_num, num

        for(int i=0; i<sz; i++) {
            mapped_nums[i] = { map_num(mapping, nums[i]), nums[i] };
            cout << "mapped_num[i]= " << mapped_nums[i].first << " num[i]= "<< nums[i] << endl;
        };
        stable_sort(mapped_nums.begin(), mapped_nums.end(), [](pair<int, int> first, pair<int, int> second) { return first.first <= second.first;});

        vector<int> res(sz, 0);
        for(int i=0; i<sz; i++) {
            res[i] = mapped_nums[i].second;
        }

        return res;
    }

    int map_num(vector<int>& mapping, int num) {
        int res = 0;
        if(num == 0 )
            res = mapping[0];
        int num_digits = 0;
        while(num > 0) {
            int low_digit = num % 10;
            cout << "low_digit= " << low_digit << endl;
            res = res + mapping[low_digit]*pow(10, num_digits);
            cout << "res= " << res << endl;
            num = num / 10;
            num_digits++;
        }
        return res;
    }
};