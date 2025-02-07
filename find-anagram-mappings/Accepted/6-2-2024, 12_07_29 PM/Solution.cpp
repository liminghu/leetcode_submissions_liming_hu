// https://leetcode.com/problems/find-anagram-mappings

class Solution {
public:
    vector<int> anagramMappings(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        unordered_map<int, vector<int>> mp2;
        
        for(int i=0; i<nums2.size(); i++) {
            mp2[nums2[i]].push_back(i);
        };
        
        for(int i=0; i<nums1.size(); i++) { 
            // index mapping array mapping from nums1 to nums2 where 
            //mapping[i] = j means the ith element in nums1 appears in nums2 at index j
            if(mp2[nums1[i]].size()>0) {
                ans.push_back(mp2[nums1[i]][0]);
                mp2[nums1[i]].erase(mp2[nums1[i]].begin());
            }
        }
        return ans;
        
    }
};