// https://leetcode.com/problems/kids-with-the-greatest-number-of-candies

/*
There are n kids with candies. You are given an integer array candies, where each candies[i] 
represents the number of candies the ith kid has, and an integer extraCandies, denoting the 
number of extra candies that you have.
Return a boolean array result of length n, where result[i] is true if, after giving the ith 
kid all the extraCandies, they will have the greatest number of candies among all the kids, 
or false otherwise.
Note that multiple kids can have the greatest number of candies.
n == candies.length
2 <= n <= 100
1 <= candies[i] <= 100
1 <= extraCandies <= 50
*/
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int sz = candies.size();
        int max_candy = -1;
        for(int i=0; i<sz; i++)
            max_candy = max(max_candy, candies[i]);

        vector<bool> rets(sz, false);
        for(int i=0; i<sz; i++) {
            if(candies[i]+extraCandies >= max_candy)
                rets[i] = true;
        }
        return rets;
    }
};