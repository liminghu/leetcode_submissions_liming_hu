// https://leetcode.com/problems/calculate-amount-paid-in-taxes

class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        double tax = 0;
        int upper_i = 0;
        int prev_upper = 0;
        for(int i=0; i<brackets.size(); i++) {
            upper_i = brackets[i][0];
            double percent_i = brackets[i][1]*1.0/100;
            if(income>=upper_i && i!=brackets.size()-1) 
                tax += (upper_i-prev_upper)*percent_i;
            else {
                tax += (income-prev_upper)*percent_i;
                break;
            }
            prev_upper = upper_i; 
        }
        return tax;
    }
};