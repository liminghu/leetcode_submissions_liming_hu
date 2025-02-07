// https://leetcode.com/problems/add-digits

class Solution {
public:
    int addDigits(int num) {
        if (num <10) return num;
        int sumDigits = 0;
        while(num>=10) {
            sumDigits += num % 10;
            num /= 10;
            if (num < 10) {
                sumDigits +=num;
                num=sumDigits;
                sumDigits = 0;
            };
        }
        return num;
        
    }
};