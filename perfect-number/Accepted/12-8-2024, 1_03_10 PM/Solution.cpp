// https://leetcode.com/problems/perfect-number

class Solution {
public:
    bool checkPerfectNumber(int num) {
        int sum = 0;
        int st = sqrt(num);
        while(st>0) {
            if(st!=num && num%st == 0) {
                sum += st;
                if(num/st != st && num/st!=num)
                    sum+= (num/st);
            };
            st--;
        }
        return num==sum;
    }
};