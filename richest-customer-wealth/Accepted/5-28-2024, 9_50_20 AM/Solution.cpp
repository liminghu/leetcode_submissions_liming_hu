// https://leetcode.com/problems/richest-customer-wealth

class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans=0;
        for(int i=0; i<accounts.size(); i++)  { //customers.
            int balance=0;
            for(int j=0; j<accounts[i].size(); j++)  { //accounts.
                balance += accounts[i][j];
            }
            if (balance >ans )
                ans = balance;
        }
        return ans;
    }
};