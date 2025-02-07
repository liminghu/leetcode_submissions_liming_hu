// https://leetcode.com/problems/minimum-cost-to-make-arrays-identical

class Solution {
public:
    long long minCost(vector<int>& arr, vector<int>& brr, long long k) {
        int n = arr.size();
        long long res1=0;
        long long res2=0;
        for(int i=0; i<n; i++)
            res1 += abs(arr[i]-brr[i]);
        sort(arr.begin(), arr.end());
        sort(brr.begin(), brr.end());
        for(int i=0; i<n; i++)
            res2 += abs(arr[i]-brr[i]);
        return min(res1, res2+k);        
    }
};