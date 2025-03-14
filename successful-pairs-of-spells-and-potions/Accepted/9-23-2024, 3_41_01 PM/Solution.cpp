// https://leetcode.com/problems/successful-pairs-of-spells-and-potions

/*
You are given two positive integer arrays spells and potions, of length n and m respectively, 
where spells[i] represents the strength of the ith spell and potions[j] represents the strength
 of the jth potion.
You are also given an integer success. A spell and potion pair is considered successful if 
the product of their strengths is at least success.
Return an integer array pairs of length n where pairs[i] is the number of potions that will 
form a successful pair with the ith spell.
n == spells.length
m == potions.length
1 <= n, m <= 105
1 <= spells[i], potions[i] <= 105
1 <= success <= 1010
*/
class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end()); //m, increasing.
        int m = potions.size();
        int maxPosition = potions[m-1];
        vector<int> rets;
        for(int i=0; i<spells.size(); i++) {
            long long minPosition = ceil( (1.0*success)/spells[i] );
            if(minPosition > maxPosition) {
                rets.push_back(0);
                continue;
            }
            auto iter = lower_bound(potions.begin(), potions.end(), minPosition);
            int num = iter-potions.begin();
            rets.push_back(m-num);
        };
        return rets;
    }
};