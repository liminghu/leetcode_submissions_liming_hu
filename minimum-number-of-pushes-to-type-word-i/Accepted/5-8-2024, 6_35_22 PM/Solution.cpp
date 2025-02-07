// https://leetcode.com/problems/minimum-number-of-pushes-to-type-word-i

class Solution {
public:
    int minimumPushes(string word) {
        int cost = 0;
        if (word.size() <=8) 
            return word.size();
        cost = 8;
        if(word.size()<=16) {
            cost+= (word.size() - 8)*2;
            return cost;
        } 
        cost = 8+8*2;
        if(word.size()<=24) {
            cost += (word.size() - 16)*3;
            return cost;
        };
        cost = 8+8*2+8*3;
        if(word.size()<=26) {
            cost += (word.size() - 24)*4;
        };
        return cost;

    }
};