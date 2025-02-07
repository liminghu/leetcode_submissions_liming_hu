// https://leetcode.com/problems/next-greater-element-i

class Solution {
public:
    //All integers in nums1 and nums2 are unique.
    //All the integers of nums1 also appear in nums2.
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {//nums1 is a subset of nums2.
    //For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.
    //Return an array ans of length nums1.length such that ans[i] is the next greater element as described above.
        int n = nums1.size();
        vector<int> ans(n, -1);
        unordered_map<int, int> map1;
      
        int m = nums2.size();
        
        stack<int> stack;
        for(int i=0; i<m; i++) {
            while(!stack.empty() && nums2[i]>nums2[stack.top()]) {
                map1[nums2[stack.top()]] = nums2[i];
               stack.pop();
            };
            stack.push(i);
        }

        for(int i=0; i<n; i++) {
            if(map1[nums1[i]]) {
               ans[i] =  map1[nums1[i]];
            }
        }
        return ans; 
    }
};