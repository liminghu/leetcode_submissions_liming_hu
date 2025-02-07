// https://leetcode.com/problems/maximum-number-of-integers-to-choose-from-a-range-ii

class Solution {
public:
    int maxCount(vector<int>& banned, int n, long long maxSum) {
        sort(banned.begin(), banned.end());
        vector<int> sorted_banned;
        for(int i=0; i<banned.size(); i++) {  //remove repeated numbers.
            if(i==0 || banned[i]!=sorted_banned.back())
                sorted_banned.push_back(banned[i]);
        }
        int m = sorted_banned.size();
        vector<long long> preSum(m, 0);
        preSum[0] = sorted_banned[0];
        for(int i=1; i<m; i++)
            preSum[i] = preSum[i-1]+sorted_banned[i];

        long long  lo = 1;
        long long  hi = n;
        while(lo<hi) {
            int mid = lo+(hi-lo)/2+1;
            long long sum = (long long)mid*(mid+1)/2;
            int index = upper_bound(sorted_banned.begin(), sorted_banned.end(), mid) - sorted_banned.begin();
            if(index > 0)
                sum -= preSum[index-1];
            if(sum == maxSum)
                return mid-index;
            else if(sum > maxSum)
                hi = mid-1;
            else
                lo = mid;
        }
        int index = upper_bound(sorted_banned.begin(), sorted_banned.end(), lo) - sorted_banned.begin();
        return lo-index;
    }
};