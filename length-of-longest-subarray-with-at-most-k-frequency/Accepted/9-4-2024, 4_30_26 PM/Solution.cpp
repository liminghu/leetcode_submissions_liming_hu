// https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency

/*
You are given an integer array nums and an integer k.
The frequency of an element x is the number of times it occurs in an array.
An array is called good if the frequency of each element in this array is less than or equal to k.
Return the length of the longest good subarray of nums.
A subarray is a contiguous non-empty sequence of elements within an array.
1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= k <= nums.length
*/
class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int res = 0;
        int i=0;
        int n = nums.size();
        for(int j=0; j<n; j++) {
            freq[ nums[j] ]++;
            while(freq[ nums[j] ] > k) {
                freq[ nums[i]]--;
                i++;
            }
            res = max(res, j-i+1);
        }
        return res;
        
        /*int n = nums.size();
        unordered_map<int, int> freq;
        int start = 0;
        int end = 0;
        int charsWithFreqOverK = 0;
        for(end = 0; end<n; end++) {
            freq[nums[end] ]++;
            if(freq[nums[end] ] == k+1 )
                charsWithFreqOverK++;
            if(charsWithFreqOverK > 0) {
                freq[ nums[start]]--;
                if(freq[ nums[start]] == k)
                   charsWithFreqOverK--; 
                start++;
            }
        }
        return end - start;*/
    }
};