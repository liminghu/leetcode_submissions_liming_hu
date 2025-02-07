// https://leetcode.com/problems/fraction-to-recurring-decimal

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        string ans;

        //edge cases.
        if(numerator == 0)
            return "0";
        if(numerator<0 ^ denominator <0) {
            ans.append("-");
        };

        long long dividend = labs((long long)numerator);
        long long divisor = labs((long long)denominator);
        ans.append(to_string(dividend/divisor));
        long long reminder = dividend % divisor;
        if(reminder == 0) {
            return ans;
        };
        ans.append(".");

        unordered_map<long long, int> map;
        while(reminder!=0) {
            if(map.find(reminder) != map.end()) {
                ans.insert(map[reminder], "(");
                ans.append(")");
                break;
            };
            map[reminder] = ans.length();
            reminder *= 10;
            ans.append(to_string(reminder/divisor));
            reminder %= divisor;
        }
        return ans;
    }
};