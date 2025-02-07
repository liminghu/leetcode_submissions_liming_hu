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
        unordered_map<int, int> mp;
        for(auto number: nums1) {
            for(int i=1; i*i<=number; i++) {
                if(i*i == number) {
                    mp[i]++;
                } else if(number % i == 0) {
                    mp[i]++;
                    mp[number/i]++;
                }
            }
        }

        long long ans = 0;
        for(auto number: nums2) {
            number *= k;
            if( mp[number] > 0) 
                ans += mp[number];
        };
        return ans;
    }
};