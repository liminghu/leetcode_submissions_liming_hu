// https://leetcode.com/problems/paint-house-ii

/*
There are a row of n houses, each house can be painted with one of the k colors. The cost of painting each house with a certain color is different. 
You have to paint all the houses such that no two adjacent houses have the same color.
The cost of painting each house with a certain color is represented by an n x k cost matrix costs.
For example, costs[0][0] is the cost of painting house 0 with color 0; costs[1][2] is the cost of painting house 1 with color 2, and so on...
Return the minimum cost to paint all houses.

Example 1:
Input: costs = [[1,5,3],[2,9,4]]
Output: 5
Explanation:
Paint house 0 into color 0, paint house 1 into color 2. Minimum cost: 1 + 4 = 5; 
Or paint house 0 into color 2, paint house 1 into color 0. Minimum cost: 3 + 2 = 5.

Example 2:
Input: costs = [[1,3],[2,4]]
Output: 5
 

Constraints:
costs.length == n
costs[i].length == k
1 <= n <= 100
2 <= k <= 20
1 <= costs[i][j] <= 20
 
Follow up: Could you solve it in O(nk) runtime?
*/
class Solution {
public:
    int minCostII(vector<vector<int>>& costs) { //n x k cost matrix costs.
        int n = costs.size();
        int k = costs[0].size();
        int min1 = -1;  //the minimum
        int min2 = -1;  // the second minimum.
        for(int i=0; i<n; i++) {
            int prevMin1 = min1;
            int prevMin2 = min2;
            min1 = -1;
            min2 = -1;
            for(int j=0; j<k; j++) {
                if( j != prevMin1 )
                    costs[i][j] += prevMin1<0? 0: costs[i-1][prevMin1];   //paint house i with color j with the cost cost[i][j], and and the previous house cost costs[i-1][prevMin1].
                else 
                    costs[i][j] += prevMin2<0? 0: costs[i-1][prevMin2];   //
                if(min1<0 || costs[i][j] < costs[i][min1]) {
                    min2 = min1;
                    min1 = j;
                } else if(min2<0 || costs[i][j]<costs[i][min2]) 
                    min2 = j;
            }
        }
        return costs[n-1][min1];
    }
};