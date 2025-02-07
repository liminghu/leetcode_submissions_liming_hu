// https://leetcode.com/problems/arranging-coins

class Solution {
public:
    int arrangeCoins(int n) {
        int ans = 0;
        int num_coins = 0;
        int i=1;
        while(num_coins <n) {
            num_coins+=i;
            i++;
        };

        if(num_coins>n)
            return i-2;
        else
            return i-1;

    }
};