// https://leetcode.com/problems/tuple-with-same-product

/*
Given an array nums of distinct positive integers, return the number of tuples (a, b, c, d) such that a * b = c * d 
where a, b, c, and d are elements of nums, and a != b != c != d.
*/
class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                mp[nums[i]*nums[j]]++;
            }
        };
        int ret = 0;
        for(auto item: mp) {
            int prod = item.first;
            int cnt = item.second;
            if (cnt > 1)
                ret += (cnt-1)*cnt/2;
        };
        return 8*ret; //a b c d   (b a) cd  ab ( d c)    (cd ) (ab)....   2*2*2. 
    }
};