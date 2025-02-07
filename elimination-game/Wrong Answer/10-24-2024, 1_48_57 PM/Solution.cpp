// https://leetcode.com/problems/elimination-game

class Solution {
public:
    int lastRemaining(int n) {
        if(n==1)
            return 1;
        return (int)sqrt(n) * 2;
    }
};