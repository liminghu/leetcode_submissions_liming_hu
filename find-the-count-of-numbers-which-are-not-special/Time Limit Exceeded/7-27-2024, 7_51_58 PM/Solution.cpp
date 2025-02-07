// https://leetcode.com/problems/find-the-count-of-numbers-which-are-not-special

class Solution {
public:
    int nonSpecialCount(int l, int r) { //1 <= l <= r <= 109
        /*
        You are given 2 positive integers l and r. For any number x, all positive divisors of x except x are called the proper divisors of x.

        A number is called special if it has exactly 2 proper divisors. For example:

        The number 4 is special because it has proper divisors 1 and 2.
        The number 6 is not special because it has proper divisors 1, 2, and 3.
        Return the count of numbers in the range [l, r] that are not special.
        */
        int cnt_special = 0;
        for(int i=l; i<=r; i++) {
            if(i<=3)
                continue;
            if(isSpecial(i))
                cnt_special++;
        }
        return (r-l)+1-cnt_special;

    }

    bool isSpecial(int num) {
        int sqt = sqrt(num);
        bool prime = isPrime(sqt);
        bool ans = (sqt*sqt == num);

        if(ans == false)
            return false;
        if (!prime)
            return false;
        return true;
    }
    bool isPrime(int number){

        if(number < 2) return false;
        if(number == 2) return true;
        if(number % 2 == 0) return false;
        for(int i=3; (i*i)<=number; i+=2){
            if(number % i == 0 ) return false;
        }
        return true;

    }
};