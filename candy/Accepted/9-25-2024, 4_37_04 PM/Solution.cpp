// https://leetcode.com/problems/candy

/*
There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.
You are giving candies to these children subjected to the following requirements:
Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.
n == ratings.length
1 <= n <= 2 * 104
0 <= ratings[i] <= 2 * 104
*/
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> assigned(n,1);
        for(int i=1; i<n; i++) {
            if(ratings[i] > ratings[i-1]) //look left
                assigned[i] = max(assigned[i], assigned[i-1]+1);
        }
        for(int i=n-2; i>=0; i--) {
            if(ratings[i] > ratings[i+1]) //look right.
                assigned[i] = max(assigned[i], assigned[i+1]+1);
        };
        int sum = accumulate(assigned.begin(), assigned.end(), 0);
        return sum;
    }
};