// https://leetcode.com/problems/maximum-of-absolute-value-expression

/*
Given two arrays of integers with equal lengths, return the maximum value of:
|arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|
where the maximum is taken over all 0 <= i, j < arr1.length.
2 <= arr1.length == arr2.length <= 40000
-10^6 <= arr1[i], arr2[i] <= 10^6
 */
class Solution {
public:
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int n=arr1.size();
        int i,j,k;
        vector<int> bucket1(n,0);
        vector<int> bucket2(n,0);
        vector<int> bucket3(n,0);
        vector<int> bucket4(n,0);
        for( i=0; i<n; i++) {
            bucket1[i] = arr1[i] + arr2[i] + i;
            bucket2[i] = arr1[i] + arr2[i] - i;
            bucket3[i] = arr1[i] - arr2[i] + i;
            bucket4[i] = arr1[i] - arr2[i] - i;
        }
        
        // for each index 
        int ans = 0;
        int max_bucket1=bucket1[0], max_bucket2=bucket2[0], max_bucket3=bucket3[0], max_bucket4=bucket4[0];
        int min_bucket1=bucket1[0], min_bucket2=bucket2[0], min_bucket3=bucket3[0], min_bucket4=bucket4[0];
        for(i=0; i<n; i++) {
           max_bucket1 = max(max_bucket1,bucket1[i]);
           min_bucket1 = min(min_bucket1,bucket1[i]);
 
           max_bucket2 = max(max_bucket2,bucket2[i]);
           min_bucket2 = min(min_bucket2,bucket2[i]);
           max_bucket3 = max(max_bucket3,bucket3[i]);
           min_bucket3 = min(min_bucket3,bucket3[i]);
            
           max_bucket4 = max(max_bucket4,bucket4[i]);
           min_bucket4 = min(min_bucket4,bucket4[i]);
        }
        int max1 = max(max_bucket1-min_bucket1, max_bucket2-min_bucket2);
        int max2 = max(max_bucket3-min_bucket3, max_bucket4-min_bucket4);
        return max(max1, max2);
    }
};