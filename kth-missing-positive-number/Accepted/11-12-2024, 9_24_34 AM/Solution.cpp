// https://leetcode.com/problems/kth-missing-positive-number

class Solution {
public:
    /*int findKthPositive1(vector<int>& arr, int k) {
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
    }*/
    int findKthPositive(vector<int>& arr, int k) {
        for(int num: arr) { //sorted.
            if( num <= k) //This step accounts for the missing positive integers. If the number is less than or equal to k, 
                          //it means we've encountered an actual element of the sequence, so the k-th missing positive integer is 
                          //pushed further by one.
                k++;
            else   //This happens because there’s no need to continue iterating once we’ve passed the range where the k-th missing integer could exist.
                break;
        }
        return k;
    }
};