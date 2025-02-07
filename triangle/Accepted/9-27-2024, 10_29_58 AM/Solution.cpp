// https://leetcode.com/problems/triangle

/*
Given a triangle array, return the minimum path sum from top to bottom.
For each step, you may move to an adjacent number of the row below. More formally, 
if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.
1 <= triangle.length <= 200
triangle[0].length == 1
triangle[i].length == triangle[i - 1].length + 1
-104 <= triangle[i][j] <= 104
 
Follow up: Could you do this using only O(n) extra space, where n is the total number of rows in the triangle?
*/
class Solution {
public:
    //[[2],                [[2]]
    // [3,4],               [5,  6],
    // [6,5,7],             [11, 10,  11],
    // [4,1,8,3]]           [15, 11,  18, 14]]
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        auto& t = triangle;

        //t[i][j] = mintotalof(i, j)
        //t[i][j] += min(t[i-1][j], t[i-1][j-1]);
        for(int i=0; i<n; i++) {
            for(int j=0; j<=i; j++) {
                if( i==0 && j==0 )
                    continue;
                if( j == 0 )
                    t[i][j] += t[i-1][j];
                else if( j == i )
                    t[i][j] += t[i-1][j-1];
                else
                    t[i][j] += min(t[i-1][j-1], t[i-1][j]);
            }
        }
        return *min_element(t[n-1].cbegin(), t[n-1].cend()); 
/*        int n = triangle.size();
        //f[i][j] = mintotalof(i, j)
        //f[i][j] = min(f[i-1][j], f[i-1][j-1]) + triangle[i-1][j-1];
        vector<vector<int>> f(2, vector<int>(n+1, INT_MAX));
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=i; j++) {
                f[1][j] = triangle[i-1][j-1];
                if( i==1 && j==1 )
                    continue;
                if( j == 1 )
                    f[1][j] += f[0][j];
                else if( j == i )
                    f[1][j] += f[0][j-1];
                else
                    f[1][j] += min(f[0][j-1], f[0][j]);
            }
            swap(f[0], f[1]);
        }
        return *min_element(f[0].begin(), f[0].end()); */
/*        int n = triangle.size();
        //f[i][j] = mintotalof(i, j)
        //f[i][j] = min(f[i-1][j], f[i-1][j-1]) + triangle[i-1][j-1];
        vector<vector<int>> f(n+1, vector<int>(n+1, INT_MAX));
        for(int i=1; i<=n; i++) {
            for(int j=1; j<=i; j++) {
                f[i][j] = triangle[i-1][j-1];
                if( i==1 && j==1 )
                    continue;
                if( j == 1 )
                    f[i][j] += f[i-1][j];
                else if( j == i )
                    f[i][j] += f[i-1][j-1];
                else
                    f[i][j] += min(f[i-1][j-1], f[i-1][j]);
            }
        }
        return *min_element(f[n].begin(), f[n].end()); */
    }
};