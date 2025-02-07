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
        unordered_map<int, int> basket;
        int i = 0;
        int j = 0;
        for(; j<n; j++) {
            basket[fruits[j]]++;
            if(basket.size()>2) {
                basket[fruits[i]]--;
                if(basket[fruits[i]]==0)
                    basket.erase(fruits[i]);
                i++;
            };
            ret = max(ret, j-i+1);
        }
        return ret;
    }
};