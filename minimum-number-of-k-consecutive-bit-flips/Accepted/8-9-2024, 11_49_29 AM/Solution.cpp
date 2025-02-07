// https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips

/*
You are given a binary array nums and an integer k.
A k-bit flip is choosing a subarray of length k from nums and simultaneously changing 
every 0 in the subarray to 1, and every 1 in the subarray to 0.
Return the minimum number of k-bit flips required so that there is no 0 in the array. 
If it is not possible, return -1.
A subarray is a contiguous part of an array.
*/
class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        //1 <= nums.length <= 105
        //1 <= k <= nums.length
        int sz = nums.size();
        int res = 0;
        queue<int> q;
        for(int i=0; i<sz; i++) {
            while(!q.empty() && i>q.front()+k-1)
                q.pop();
            if((nums[i] + q.size()) %2 == 0) {
                if(i+k > sz)
                    return -1;
                res++;
                q.push(i);
            }
        }
        return res;





/*        int sz = nums.size();
        int res = 0;
        for(int i=0; i<sz; i++) {
            if(nums[i]==0 && i>=sz-k+1)
                return -1;
            if(nums[i] == 0) {
                nums[i] = 1;
                //i+1   i+k-1
                for(int j=i+1; j<=i+k-1; j++) {
                    nums[j] = 1 - nums[j]; 
                }
                res++;
            } 
        }

        return res;*/
    }
};