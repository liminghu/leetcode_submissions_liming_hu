// https://leetcode.com/problems/reverse-pairs

class Solution {
public:
    int reversePairs(vector<int>& nums) {
        /*  A reverse pair is a pair (i, j) where:
            0 <= i < j < nums.length and
            nums[i] > 2 * nums[j].
        */
        int n = nums.size();
        return mergesortCount(nums, 0, n-1);
    }
    int mergesortCount(vector<int>& nums, int start, int end) {
        if(start<end) {
            int mid = (start+end)/2;
            int count = mergesortCount(nums, start, mid) + mergesortCount(nums, mid+1, end);
            int j = mid+1;
            for(int i=start; i<=mid; i++) {
                while(j<=end && nums[i]> 2LL*nums[j])
                    j++;
                count += j-(mid+1);
            }
            merge(nums, start, mid, end);
            return count;
        } else
            return 0;
    }
    void merge(vector<int>& nums, int start, int mid, int end) {
        int n1 = mid-start+1;
        int n2 = end-mid;
        vector<int> L(n1, 0), R(n2, 0);
        for(int i=0; i<n1; i++)
            L[i] = nums[start+i];
        for(int j=0; j<n2; j++)
            R[j] = nums[mid+1+j];
        int i=0, j=0;
        for(int k=start; k<=end; k++) {
            if(j>=n2 || (i<n1 && L[i]<=R[j]))
                nums[k] = L[i++];
            else
                nums[k] = R[j++];
        };        
    }
};