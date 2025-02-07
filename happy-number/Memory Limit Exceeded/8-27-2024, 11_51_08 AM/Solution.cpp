// https://leetcode.com/problems/happy-number

/*
Write an algorithm to determine if a number n is happy.
A happy number is a number defined by the following process:
Starting with any positive integer, replace the number by the 
sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), 
or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.
*/
class Solution {
public:
    bool isHappy(int n) {
        //1 <= n <= 231 - 1
        unordered_set<int> set(n);
        int start = n;
        while( n!=1) {
            int sumSqure = 0;
            while(n>0) {
                int digits = n%10;
                sumSqure += digits*digits;
                n = n/10;  
            };
            n = sumSqure;            
            if(n == 1)
                return true;
            if(set.find(n)!=set.end())
                return false;
            else
                set.insert(n);            
        }

        return n==1;
    }
};