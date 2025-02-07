// https://leetcode.com/problems/regions-cut-by-slashes

/*
An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of 
a '/', '\', or blank space ' '. These characters divide the square into contiguous regions.
Given the grid grid represented as a string array, return the number of regions.
Note that backslash characters are escaped, so a '\' is represented as '\\'.
*/
class Solution {
public:
    vector<int> father;
    int regionsBySlashes(vector<string>& grid) {
        /*  n == grid.length == grid[i].length
            1 <= n <= 30
            grid[i][j] is either '/', '\', or ' '.
        */
        int sz = grid.size();
        int res = 1; //at least one area.
        father.resize((sz+1)*(sz+1));

        //initialize
        for(int i=0; i<=sz; i++) {
            for(int j=0; j<=sz; j++) {
                int idx = i*(sz+1)+j;
                father[idx] = idx;
                if(i==0 || i==sz || j==0 || j==sz ) 
                    father[idx] = 0;
            }
        }

       for(int i=0; i<sz; i++) {
            for(int j=0; j<sz; j++) {
                if(grid[i][j] == ' ')
                    continue;
                else if (grid[i][j] == '/') {
                    int a = i*(sz+1) + (j+1);
                    int b = (i+1)*(sz+1)+j;
                    if(FindFather(a) == FindFather(b))
                        res++;
                    else
                        Union(a,b);

                } else if (grid[i][j] == '\\') {
                    int a = i*(sz+1) + j;
                    int b = (i+1)*(sz+1)+j+1;
                    if(FindFather(a) == FindFather(b))
                        res++;
                    else
                        Union(a,b);                    
                }
            }
       }
        return res;       
    }
    int FindFather(int x) {
        if(father[x] != x)
            father[x] = FindFather(father[x]);
        return father[x];
    }
    void Union(int x, int y) {
        x = FindFather(x);
        y = FindFather(y);
        if( x < y )
            father[y] = x;
        else
            father[x] = y;
    }
};