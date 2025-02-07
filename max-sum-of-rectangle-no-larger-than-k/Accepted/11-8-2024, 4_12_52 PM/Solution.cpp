// https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int K) {
        int m = matrix.size(); //rows
        int n = matrix[0].size(); //cols.
        int res = INT_MIN;
        if(m>n) {
            vector<vector<int>> matrix2(n, vector<int>(m,0));
            for(int i=0; i<m; i++) 
                for(int j=0; j<n; j++)
                    matrix2[j][i] = matrix[i][j];
            return maxSumSubmatrix(matrix2, K);
        };

        for(int i=0; i<m; i++) {   //start row.
            vector<int> row(n, 0);
            for(int j=i; j<m; j++) {//end row.
                for(int k=0; k<n; k++) 
                    row[k] = row[k] + matrix[j][k]; //compress all the rows to one row.
                res = max(res, helper(row, K));    
            } ;   
        };
        return res;
    }
    int helper(vector<int>& nums, int K) {
        int n = nums.size();
        int presum = 0;
        multiset<int> Set({0});
        int res = INT_MIN;
        for(int j=0; j<n; j++) {
            presum += nums[j];
            auto iter = Set.lower_bound(presum-K);
            if(iter != Set.end()) 
                res = max(res, presum-*iter);
            Set.insert(presum);
        }
        return res;
    }
};