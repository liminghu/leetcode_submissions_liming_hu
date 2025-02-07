// https://leetcode.com/problems/maximum-subarray-sum-with-one-deletion

class Solution {
public:
/*
Given an array of integers, return the maximum sum for a non-empty subarray (contiguous elements) with at most one element deletion. 
In other words, you want to choose a subarray and optionally delete one element from it so that there is still at least one element 
left and the sum of the remaining elements is maximum possible.
Note that the subarray needs to be non-empty after deleting one element.
*/

    int maximumSum(vector<int>& arr) {
    int size = arr.size();
      /*  if ( size == 1 ) return arr[ 0 ];

		// dropped record the maximum sum ended at current index with one number being dropped
        int dropped = max( arr[ 0 ], arr[ 1 ] );
        // not dropped must take arr[ 1 ] at index = 1
        int notDropped = max( arr[ 0 ] + arr[ 1 ], arr[ 1 ] );
        int ans = max( dropped, notDropped );
            
        for ( int i = 2; i < size; i++ ) {
            dropped = max( notDropped, arr[ i ] + dropped );
            notDropped = max( notDropped + arr[ i ], arr[ i ] );
            ans = max( ans, max( dropped, notDropped ) );
        }
        return ans;*/
        int sz = arr.size();
        if(sz == 1) 
            return arr[0];
 
        vector<vector<int>> dp(sz, vector<int>(2,0));
        dp[0][0] = arr[0];
        dp[0][1] = arr[0];

        dp[1][0] = max(arr[0]+arr[1], arr[1]);
        dp[1][1] = max(arr[0], arr[1]);


        for(int i=2; i<sz; i++) {
            dp[i][0] = max(dp[i-1][0]+arr[i], arr[i]);
            dp[i][1] = max(dp[i-1][0], dp[i-1][1]+arr[i]);
        }

        int ret = INT_MIN;
        for(int i=0; i<sz; i++) {
            ret = max(ret,dp[i][0]);
            ret = max(ret,dp[i][1]);
        }

        return ret;
        
    }
};