// https://leetcode.com/problems/find-the-length-of-the-longest-common-prefix

class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> arr1Prefixes;
        for(auto num:arr1) {
            while(!arr1Prefixes.count(num) && num>0) {
                arr1Prefixes.insert(num);
                num /=10;
            }
        };
        int ret = 0;
        for(auto num:arr2) {
            while(!arr1Prefixes.count(num) && num>0) {
                num /=10;
            }
            if(num>0)
                ret = max(ret, (int)to_string(num).length());
        };
        return ret;
    }

};