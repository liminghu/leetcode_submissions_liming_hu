// https://leetcode.com/problems/intersection-of-two-arrays

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        //easy with hashtable.
        unordered_map<int, int> values;
        for(int i=0; i<nums1.size(); i++) {
            if(values.find(nums1[i]) == values.end())
                values[nums1[i]] = 1;
        };
        
        vector<int> ans;
        for(int i=0; i<nums2.size(); i++) {
            if(values.find(nums2[i]) != values.end())
                if(values[nums2[i]] == 1) {
                    values[nums2[i]]++;
                    ans.push_back(nums2[i]);
                } else { //duplicate
                    values[nums2[i]]++;
                }
        }
        return ans;
    }
};