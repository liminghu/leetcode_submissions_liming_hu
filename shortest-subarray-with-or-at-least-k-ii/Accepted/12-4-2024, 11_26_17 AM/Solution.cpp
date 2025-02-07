// https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 1;
        int right = n;
        while(left<right) {
            int mid = left + (right-left)/2;
            if(isOK(nums, mid, k))
                right = mid;
            else
                left = mid+1;
        }
        if(!isOK(nums, left, k))
            return -1;
        return left;
    }
    bool isOK(vector<int>& nums, int len, int k) {
        vector<int> count(32);
        for(int i=0; i<len-1; i++) {
            for(int j=0; j<32; j++)
                count[j] += ( (nums[i]>>j) & 1 );
        };
        for(int i=len-1; i<nums.size(); i++) {
            for(int j=0; j<32; j++)
                count[j] += ( (nums[i]>>j) & 1 );
            int sum = 0;
            for(int j=0; j<32; j++)
                if(count[j]>0) 
                    sum+= (1<<j);
            if(sum>=k)
                return true;
            for(int j=0; j<32; j++)
                count[j] -= ( (nums[i-len+1]>>j) & 1 );
        }
        return false;
    }
};