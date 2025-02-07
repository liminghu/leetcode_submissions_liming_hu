// https://leetcode.com/problems/fruit-into-baskets

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        /*You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
        Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
        Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
        Given the integer array fruits, return the maximum number of fruits you can pick.
        */
        int ret = 0;
        int n = fruits.size();
        unordered_map<int, int> count;
        int i = 0;
        int j = 0;
        for(; j<n; j++) {
            count[fruits[j]]++;
            if(count.size()>2) {
                count[fruits[i]]--;
                if(count[fruits[i]]==0)
                    count.erase(fruits[i]);
                i++;
            };
        }
        return j-i;
    }
};