// https://leetcode.com/problems/zero-array-transformation-ii

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        //queries[i] = [li, ri, vali]. 1 <= vali <= 5
        //Decrement the value at each index in the range [li, ri] in nums by at most vali.
        //The amount by which each value is decremented can be chosen independently for each index.
        //Return the minimum possible non-negative value of k, such that after processing the first k queries in sequence, nums becomes a Zero Array. If no such k exists, return -1.
        int n = nums.size();
        int sum = 0;
        int k = 0;
        vector<int> cnt(n+1, 0);
        for(int i=0; i<n; i++) {
            while(sum+cnt[i] < nums[i]) {
                if(k==queries.size())
                    return -1;
                int l = queries[k][0];
                int r = queries[k][1];
                int val = queries[k][2];
                k++;
                if(r<i)
                    continue;
                cnt[max(l, i)] += val;
                cnt[r+1]-=val;
            }
            sum+= cnt[i];
        }
        return k;
    }
};