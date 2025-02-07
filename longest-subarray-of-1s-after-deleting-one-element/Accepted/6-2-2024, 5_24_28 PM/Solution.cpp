// https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element

class Solution {
public:
    int longestSubarray(vector<int>& nums) { //longest subarray contains at most one 0.
        //Maintain a sliding window where there is at most one zero on it.
    
        //int number of zero's in the window
        int zeroCount = 0;
        int longestWindow =0;
        //left of the window
        int start = 0;
        
        for(int i=0; i<nums.size(); i++) {
            zeroCount += (nums[i]==0);

            //shrink the window until the zero counts under the limit
            while(zeroCount>1) {
                zeroCount -= (nums[start]==0);
                start++;
            }
            longestWindow = max(longestWindow, i-start);
        } 

        return longestWindow;
    }
};