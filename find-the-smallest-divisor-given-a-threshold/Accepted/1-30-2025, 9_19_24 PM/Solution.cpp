// https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int left = 1, right = 1e6;
        int sum, mid;
        while(left<right) {
            mid = (left+right)/2;
            sum = 0;
            for(int num:nums)
                sum+= ceil(1.0*num/mid);
            if(sum>threshold)
                left = mid+1;
            else
                right = mid;
        }
        return left;
    }
};