// https://leetcode.com/problems/find-missing-observations

class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        int sum_m = 0;
        for(int dice: rolls)
            sum_m+= dice;
        int sum_n = mean*(m+n)- sum_m;
        if(sum_n < n || sum_n > 6*n)
            return {};
        vector<int> ans(n, sum_n/n);
        int rem = sum_n%n;
        for(int i=0; i<rem; i++) 
            ans[i]+=1;
        return ans;
    }
};