// https://leetcode.com/problems/count-of-range-sum

class Solution {
int result;
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<long> presum(n+1, 0);
        for(int i=0; i<n; i++)
            presum[i+1] = presum[i] + nums[i];
        divideConquer(presum, 0, n, lower, upper);
        return result;
    }
    void divideConquer(vector<long>& presum, int a, int b, int lower, int upper) {
        if( a >= b )
            return;
        int mid = a+(b-a)/2;
        divideConquer(presum, a, mid, lower, upper);
        divideConquer(presum, mid+1, b, lower, upper);
        for(int i=a; i<=mid; i++) {
            auto p1 = lower_bound(presum.begin()+mid+1, presum.begin()+b+1, presum[i]+lower);
            auto p2 = upper_bound(presum.begin()+mid+1, presum.begin()+b+1, presum[i]+upper);
            result += p2-p1;
        }
       // Merges two consecutive sorted ranges: [first,middle) and [middle,last), putting the result into the combined sorted range [first,last).
        inplace_merge(presum.begin()+a, presum.begin()+mid+1, presum.begin()+b+1);
    };
};