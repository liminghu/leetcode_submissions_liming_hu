// https://leetcode.com/problems/maximum-number-of-ways-to-partition-an-array

/*
You are given a 0-indexed integer array nums of length n. The number of ways to partition nums is the number of pivot indices that satisfy both conditions:

1 <= pivot < n
nums[0] + nums[1] + ... + nums[pivot - 1] == nums[pivot] + nums[pivot + 1] + ... + nums[n - 1]
You are also given an integer k. You can choose to change the value of one element of nums to k, or to leave the array unchanged.

Return the maximum possible number of ways to partition nums to satisfy both conditions after changing at most one element.
*/
//https://leetcode.com/problems/maximum-number-of-ways-to-partition-an-array/solutions/1498999/c-o-n/?envType=company&envId=google&favoriteSlug=google-thirty-days
class Solution {
public:
    int waysToPartition(vector<int>& nums, int k) {
        /*n == nums.length
            2 <= n <= 105
            -105 <= k, nums[i] <= 105
        */
               
        int sz = nums.size();
        vector<long long> prefix_sum(sz), suff_sum(sz);

        //store prefix and suffix sum
        prefix_sum[0] = nums[0]; suff_sum[sz-1] = nums[sz-1];
        for(int i=1; i<sz; ++i) { 
            prefix_sum[i]     = prefix_sum[i-1] + nums[i]; 
            suff_sum[sz-1-i] = suff_sum[sz-i] + nums[sz-1-i];
        } 
 
        long long ans = 0;
        //Thus, we maintain two hash maps, left & right, which store the count of differences.
        //left stores the count of difference for j < i && right stores for j >= i, where i is the index of element which we are changing to K.
        unordered_map<long long,long long> left;
        unordered_map<long long,long long> right; //key: prefix_sum - suff_sum
        
        //intially store the differences in the hashmap right
        for(int i=0;i<sz-1; ++i) //1 <= pivot < n
            right[prefix_sum[i] - suff_sum[i+1]]++;
        
        if(right.count(0)) 
            ans = right[0];

        for(int i=0; i<sz; ++i) {
        /*We can easily see, all values from pref[ j ] to pref[n-1] will also increase by d, and all values from suff[ j ] to suff[ 0 ], will also increase by d.
        So, if we had the count of all indexes i, such that:
        if i < j, then pref[ i ] - suff[ i + 1] = d, in original array i.e. without changing j's value

        Because, suffix sum from 0 to j is increased by d.
        Thus this difference will now become 0.
        Hence, i will become a pivot point.
        if i >= j, then pref [ i ] - suff[ i+1 ] = -d, in original array i.e. without changing j's value

        Because, prefix sum from j to n-1 is increased by d.
        Thus this difference will now become 0.
        Hence, i will become a pivot point.       */    

            //find the number of pivot indexes when nums[j] is changed to k
            long long curr = 0, diff = k-nums[i];
            if(left.count(diff)) 
                curr += left[diff];
            if(right.count(-diff)) 
                curr += right[-diff];

            //update answer
            ans = max(ans, curr);
            

            //transfer the current element from right to left
            if( i < sz-1 ) {
                long long dd = prefix_sum[i] - suff_sum[i+1]; 
                left[dd]++; 
                right[dd]--;
                if(right[dd] == 0) 
                    right.erase(dd);

            }
        }
        return ans; 
    }
};