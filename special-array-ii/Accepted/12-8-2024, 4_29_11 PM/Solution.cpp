// https://leetcode.com/problems/special-array-ii

class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        //queries[i] = [fromi, toi]
        vector<int> prefix(nums.size(), 0); //total number of violative indices up to index i in nums for all indices i
        prefix[0] = 0; //
        for(int i=1; i<nums.size(); i++) {
            if(nums[i]%2 == nums[i-1]%2)
                prefix[i] = prefix[i-1]+1;
            else
                prefix[i]=prefix[i-1];
        }
            

        vector<bool> rets(queries.size(), false);
        for(int i=0; i<queries.size(); i++) {
            if(queries[i][0] == queries[i][1])
                rets[i] = true;
            int start = queries[i][0];
            int end = queries[i][1];
            rets[i] = (prefix[end]-prefix[start])==0;
        }
        return rets;
        

    }
};