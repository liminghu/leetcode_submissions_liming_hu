// https://leetcode.com/problems/minimum-cost-for-cutting-cake-ii

/*
There is an m x n cake that needs to be cut into 1 x 1 pieces.

You are given integers m, n, and two arrays:

horizontalCut of size m - 1, where horizontalCut[i] represents the cost to cut along the horizontal line i.
verticalCut of size n - 1, where verticalCut[j] represents the cost to cut along the vertical line j.
In one operation, you can choose any piece of cake that is not yet a 1 x 1 square and perform one of the following cuts:

Cut along a horizontal line i at a cost of horizontalCut[i].
Cut along a vertical line j at a cost of verticalCut[j].
After the cut, the piece of cake is divided into two distinct pieces.

The cost of a cut depends only on the initial cost of the line and does not change.

Return the minimum total cost to cut the entire cake into 1 x 1 pieces.
*/
class Solution {
public:
    long long minimumCost(int m, int n, vector<int>& horizontalCut, vector<int>& verticalCut) {
        /*
        1 <= m, n <= 105
        horizontalCut.length == m - 1
        verticalCut.length == n - 1
        1 <= horizontalCut[i], verticalCut[i] <= 103
        */

        priority_queue<pair<int, int>> h_q;
        for(int i=0; i<m-1; i++) {
            h_q.push({horizontalCut[i], i});
        }
        priority_queue<pair<int, int>> v_q;
        for(int j=0; j<n-1; j++) {
            v_q.push({verticalCut[j], j});
        }

        long long ans = 0;
        int h_count = 1;
        int v_count = 1;
        while(!h_q.empty() || !v_q.empty() ) {
            if(!h_q.empty() && !v_q.empty() ) {
                pair<int, int> h_top = h_q.top();
                pair<int, int> v_top = v_q.top();
                if(h_top > v_top ) {
                    h_q.pop();
                    h_count++;
                    ans += v_count*h_top.first;
                } else {
                    v_q.pop();
                    v_count++;
                    ans += h_count*v_top.first;
                }
            } else if (h_q.empty() && !v_q.empty() ) {
                pair<int, int> v_top = v_q.top();
                v_q.pop();
                v_count++;
                ans += h_count*v_top.first;
            } else if (!h_q.empty() && v_q.empty() ) {
                pair<int, int> h_top = h_q.top();
                h_q.pop();
                h_count++;
                ans += v_count*h_top.first;
            }; 
        };
        
        return ans;
        
    }
};