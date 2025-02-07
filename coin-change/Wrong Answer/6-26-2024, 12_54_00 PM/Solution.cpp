// https://leetcode.com/problems/coin-change

class Solution { //https://leetcode.com/problems/coin-change/solutions/778548/c-dp-solution-explained-100-time-100-space/
public:
/*
You are given an integer array coins representing coins of different denominations and 
an integer amount representing a total amount of money.
Return the fewest number of coins that you need to make up that amount. If that amount of 
money cannot be made up by any combination of the coins, return -1.
You may assume that you have an infinite number of each kind of coin.
*/
    int coinChange(vector<int>& coins, int amount) { //1 <= coins.length <= 12
                                                    //1 <= coins[i] <= 231 - 1
                                                    //0 <= amount <= 104
        int sz = coins.size();

        sort(coins.begin(), coins.end());
        
        int left = amount;
        int num_coins = 0;
        for(int i=sz-1; i>=0; i--) {
            if(left == 0) 
                break;
            else {
                if( coins[i] <= left ) {
                    num_coins += left / coins[i];
                    left = left % coins[i]; 
                } else 
                    continue;
            }
        }

        if (left == 0) 
            return num_coins;
        else
            return -1;
        
    }
};