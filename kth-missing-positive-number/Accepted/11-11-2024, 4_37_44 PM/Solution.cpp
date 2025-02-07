// https://leetcode.com/problems/kth-missing-positive-number

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int left = 1;
        int right = arr.back()+k;
        while(left<right) {
            int mid = right-(right-left)/2;
            int M = mid-1;
            int T = lower_bound(arr.begin(), arr.end(), mid)-arr.begin();
            int missing = M-T;
            if(missing<=k-1)
                left = mid;
            else
                right = mid-1;
        }
        return left;
    }
};