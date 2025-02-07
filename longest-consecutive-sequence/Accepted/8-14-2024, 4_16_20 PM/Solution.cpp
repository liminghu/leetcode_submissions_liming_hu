// https://leetcode.com/problems/longest-consecutive-sequence

/*
Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
You must write an algorithm that runs in O(n) time.
*/
class Solution {
public:
    unordered_map<int,int> Father;
    int FindFather(int x) {
        if(Father[x]!=x) 
            Father[x] = FindFather(Father[x]);
        return Father[x];
    }
    void Union(int x, int y) {
        x = Father[x];
        y = Father[y];
        if(x<y) 
            Father[x] = y;
        else
            Father[y] = x;
    }
    int longestConsecutive(vector<int>& nums) {
        /*
            0 <= nums.length <= 105
            -109 <= nums[i] <= 109
        */

        unordered_set<int> nums2;
        for(int i=0; i<nums.size(); i++) {
            nums2.insert(nums[i]);
            int x = nums[i];

            if(Father.find(x)==Father.end()) {
                Father[x] = x;
            } else
                continue;

            if(Father.find(x-1) != Father.end() && FindFather(x-1)!= FindFather(x))
                Union(x-1, x);
            if(Father.find(x+1) != Father.end() && FindFather(x+1)!= FindFather(x))
                Union(x+1, x);   
        }

        //compress path.
        for(int x:nums2) {
            Father[x] = FindFather(x);
        }
        unordered_map<int, int> count;
        for(int x:nums2) {
            count[Father[x]]++;
        }
        int res = 0;
        for(auto c:count) {
            res = max(res, c.second);
        }

        return res;

/*        unordered_set<int> s(nums.begin(), nums.end());
        int res = 0;
        for(int x:s) {
            if(s.find(x-1)== s.end()) { //x is the head.
                int count = 0;
                while(s.find(x)!= s.end()) {
                    count++;
                    x++;
                }
                res = max(res, count);
            }
        }
        return res;*/

    }
};