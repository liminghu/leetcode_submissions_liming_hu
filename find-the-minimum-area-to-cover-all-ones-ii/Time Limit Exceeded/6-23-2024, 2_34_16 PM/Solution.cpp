// https://leetcode.com/problems/find-the-minimum-area-to-cover-all-ones-ii

class Solution {
public:
    /*
    You are given a 2D binary array grid. You need to find 3 non-overlapping rectangles having non-zero areas with horizontal and vertical sides such that all the 1's in grid lie inside these rectangles.

Return the minimum possible sum of the area of these rectangles.

Note that the rectangles are allowed to touch.
*/ 
    int minimumArea(vector<vector<int>>& grid, int left, int right, int top, int bottom) {
        int i, j;
        int start_row = 1e9; 
        int end_row = -1;
        int start_col = 1e9;
        int end_col = -1;
        int found = 0;
        for(i=top; i<=bottom; i++) {
            for(j=left; j<=right; j++) {
                if(grid[i][j]) {
                    start_row = min(start_row, i);
                    end_row = max(end_row,i);
                    start_col = min(start_col, j);
                    end_col = max(end_col, j);
                    found = 1;
                }
            }
        }
        int ret = found? (end_row-start_row+1)*(end_col-start_col+1): 0;
        cout << " area= " << ret << endl;
        cout << " left= " << left <<" right= " << right << " top= " << top << " bottom= " << bottom << endl;


        return ret;
    }

    int minimumSum(vector<vector<int>>& grid) { //1 <= grid.length, grid[i].length <= 30; grid[i][j] is either 0 or 1.; 
        //The input is generated such that there are at least three 1's in grid.
   
        int rows = grid.size();
        int cols = grid[0].size();
 
        int left = 0;
        int right = grid[0].size()-1;
        int top = 0;
        int bottom = grid.size()-1;
        
   

        int ans = 1e9;
        //cutting point: suppose the top-left includes the cutting point.  
        for(int i=0; i<rows; i++) {
            for(int j=0; j<cols; j++) {

                //6 cases.
                /*
                -------------
                |    (1)    |
                |           |
                -------------
                | (2) | (3) |
                |     |     |
                -------------
                */
                int area1 = 0;
                int area2 = 0;
                int area3 = 0;
                bool case1 = true;
                area1 = minimumArea(grid, 0, cols-1, 0, i); //left, right, top, bottom
                if (i+1 <rows)
                    area2 = minimumArea(grid, 0, j, i+1, rows-1);  //left, right, top, bottom
                else
                    case1 = false;
                if (i+1 <rows && j+1 <cols)
                    area3 = minimumArea(grid, j+1, cols-1, i+1, rows-1);  //left, right, top, bottom
                else 
                    case1 = false;
                if (case1 && area1>0 && area2>0 && area3 > 0)
                    ans = min(ans, area1+area2+area3);

                /*
                -------------
                | (2) | (3) |
                |     |     |
                ------------
                |           |
                |    (1)    |
                -------------
                */
                bool case2 = true;
                if (i+1 <rows)
                    area1 = minimumArea(grid, 0, cols-1, i+1, rows-1); //left, right, top, bottom
                else
                    case2 = false;
                area2 = minimumArea(grid, 0, j, 0, i);
                if (j+1 <cols)
                    area3 = minimumArea(grid, j+1, cols-1, 0, i);
                else
                    case2 = false;
                if (case2 && area1>0 && area2>0 && area3 > 0)
                    ans = min(ans, area1+area2+area3);

                /*
                -------------
                |     | (2) |
                |     |     |
                (1) -------
                |     |     |
                |     | (3) |
                -------------
                */
                bool case3 = true;
                area1 = minimumArea(grid, 0, j, 0, rows-1); //left, right, top, bottom
                if (j+1 <cols)
                    area2 = minimumArea(grid, j+1, cols-1, 0, i);
                else
                    case3 = false;
                if (i+1 <rows && j+1 <cols)
                    area3 = minimumArea(grid, j+1, cols-1, i+1, rows-1);
                else 
                    case3 = false;
                if (case3 && area1>0 && area2>0 && area3 > 0)
                    ans = min(ans, area1+area2+area3);
                /*
                -------------
                |     |     |
                | (2) |     |
                ------- (1) |
                |     |     |
                | (3) |     |
                -------------
                */
                bool case4 = true;
                if (j+1 <cols)
                    area1 = minimumArea(grid, j+1, cols-1, 0, rows-1); //left, right, top, bottom
                else 
                    case4 = false;
                area2 = minimumArea(grid, 0, j, 0, i);
                if (i+1 <rows)
                    area3 = minimumArea(grid, 0, j, i+1, rows-1);
                else 
                    case4 = false;
                if (case4 && area1>0 && area2>0 && area3 > 0)
                    ans = min(ans, area1+area2+area3);
            }
        }

        for(int i=0; i<rows; i++) {
            for(int k=i+1; k<rows; k++) {
                /*
                -------------
                |    (1)    |
                -------------
                |    (2)    |
                -------------
                |    (3)    |
                -------------
                */
                int area1 = 0;
                int area2 = 0;
                int area3 = 0;
                bool case5 = true;
                area1 = minimumArea(grid, 0, cols-1, 0, i); //left, right, top, bottom
                if (i+1 <rows)
                    area2 = minimumArea(grid, 0, cols-1, i+1, k);
                else
                    case5 = false;
                if (k+1 <rows)
                    area3 = minimumArea(grid, 0, cols-1, k+1, rows-1);
                else 
                    case5 = false;
                if (case5 && area1>0 && area2>0 && area3 > 0)
                    ans = min(ans, area1+area2+area3);
            }
        }

        for(int j=0; j<cols; j++) {
            for(int k=j+1; k<cols; k++) {
                 /*
                -------------
                |   |   |   |
                |   |   |   |
                |(1)|(2)|(3)|
                |   |   |   |
                |   |   |   |
                -------------
                */  
                int area1 = 0;
                int area2 = 0;
                int area3 = 0;
                bool case6 = true;      
                area1 = minimumArea(grid, 0, j, 0, rows-1); //left, right, top, bottom
                if (j+1 <cols)
                    area2 = minimumArea(grid, j+1, k, 0, rows-1);
                else
                    case6 = false;
                if (k+1 <cols)
                    area3 = minimumArea(grid, k+1, cols-1, 0, rows-1);
                else 
                    case6 = false;
                if (case6 && area1>0 && area2>0 && area3 > 0)
                    ans = min(ans, area1+area2+area3);
            }
        }
        
        return ans;
    }
    
};