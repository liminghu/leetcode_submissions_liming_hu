// https://leetcode.com/problems/create-maximum-number

class Solution {
public:
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> ans;
        for(int k1=0; k1<=k; k1++) {
            int k2 = k-k1;
            if(k1>m || k2>n)
                continue;
            vector<int> maxNum_k1 = maxNumber(nums1, k1);
            vector<int> maxNum_k2 = maxNumber(nums2, k2);
            ans = max(ans, maxNumber(maxNum_k1, maxNum_k2));
        }
        return ans;
    }
private:
    vector<int> maxNumber(vector<int>& nums, int k ) {
        if(k==0) 
            return {};
        int to_pop = nums.size()-k;
        vector<int> ans;
        for(auto num:nums) {
            while(!ans.empty() && num > ans.back() && to_pop > 0) {
                ans.pop_back();
                to_pop--;
            };
            ans.push_back(num);
        }   
        while(ans.size() > k)
            ans.pop_back();
        return ans; 
    } 
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        auto s1 = nums1.begin();
        auto e1 = nums1.end();
        auto s2 = nums2.begin();
        auto e2 = nums2.end();
        while(s1!=e1 || s2!=e2) {
            //Returns true if the range [first1,last1) compares lexicographically less than the range [first2,last2).
            bool cmp = lexicographical_compare(s1, e1, s2, e2);
            if(cmp) { //less
                ans.push_back(*s2);
                s2++;
            } else {
                ans.push_back(*s1);
                s1++;
            }
        }        
        return ans;
    }
   
};