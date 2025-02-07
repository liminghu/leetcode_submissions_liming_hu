// https://leetcode.com/problems/intersection-of-two-arrays-ii

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int,int> dict;

        for(int i=0; i<nums1.size(); i++) {
            dict[nums1[i]]++;
        }

        for(int i=0; i<nums2.size(); i++) {
            if (dict[nums2[i]]>0) {
                ans.push_back(nums2[i]);
                dict[nums2[i]]--;
            };
        }

        return ans;
    }
};