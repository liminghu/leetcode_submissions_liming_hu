// https://leetcode.com/problems/minimum-operations-to-make-all-array-elements-equal

using LL = long long;
class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) { //1 <= nums[i], queries[i] <= 109
        int n = nums.size();
        int m = queries.size();
        sort(nums.begin(), nums.end());
        vector<LL> rets(m, 0);
        vector<LL> prefix(n+1);
        for(int i=0; i<n; i++)
            prefix[i+1] = prefix[i] +(LL)nums[i]; //1......n
        for(int j=0; j<m; j++) {
            int num_idx = lower_bound(nums.begin(), nums.end(), queries[j])-nums.begin();
            //minimum number of operations to make all elements of nums equal to queries[i].
            /*  If there are j numbers in nums that are smaller than query[i], you need to find 
            query[i] * j - sum(j numbers smaller than query[i]) 
            to find increments required in nums
                If there are k numbers in nums that are greater than query[i], you need to find 
            sum(k numbers larger than query[i]) - query[i] * k 
            to find decrements required in nums
            */
            
            //prefix[i] is sum of numbers smaller than query[i]
            //query[i] * i - prefix[i] is increments required
            rets[j] = (LL)queries[j] * num_idx - prefix[num_idx];
            //prefix[n] - prefix[i] is sum of numbers greater than or equal to query[i]
            //prefix[n] - prefix[i] - query[j] * (n - i) is decrements required
            rets[j] += prefix[n] - prefix[num_idx] - queries[j] * (n - num_idx);
        }
        return rets;
    }
};