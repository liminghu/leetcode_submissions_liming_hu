// https://leetcode.com/problems/find-the-number-of-good-pairs-ii

/*
You are given 2 integer arrays nums1 and nums2 of lengths n and m respectively. You are also given a positive integer k.
A pair (i, j) is called good if nums1[i] is divisible by nums2[j] * k (0 <= i <= n - 1, 0 <= j <= m - 1).
Return the total number of good pairs.
Constraints:

1 <= n, m <= 105
1 <= nums1[i], nums2[j] <= 106
1 <= k <= 103
*/
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans = 0;
        int n = nums1.size();
        int m = nums2.size();
        vector<int> new_nums1, new_nums2;

        for(int i=0; i<n; i++) {
            if  (nums1[i] % k == 0 )
                new_nums1.push_back(nums1[i]/k);
        }
        sort(new_nums1.begin(), new_nums1.end());
        new_nums2 = nums2;

        sort(new_nums2.begin(), new_nums2.end());
        unordered_map<long long, bool> dict;   //<nums_i,nums_j> checked before?  


        for(int i=0; i<new_nums1.size(); i++) {
            if(new_nums1[i] == 0) {
                ans += nums2.size();
                continue;
            }
            
            for(int j=0; j<new_nums2.size(); j++) {
                if(new_nums1[i] < new_nums2[j] || new_nums2[j] == 0)
                    break;
                if(new_nums2[j] == 1) {
                    ans++;
                    continue;
                } 
                 
                 //int mod_val = new_nums1[i] - new_nums1[i]/new_nums2[j] * new_nums2[j];
                 long long key = new_nums1[i] * (long long)1000000 + new_nums2[j];
                 if( dict.find(key) != dict.end() ) {
                    if( dict[key] == 1) 
                        ans++;
                 } 
                 int mod_val = new_nums1[i] - new_nums1[i] / new_nums2[j] * new_nums2[j];
                 if(  mod_val == 0) {
                    ans++;
                    dict[key] = 1;  //true
                 } else {
                    dict[key] = 0;   //false
                 }
            }            
        }
        return ans;
        
    }
};