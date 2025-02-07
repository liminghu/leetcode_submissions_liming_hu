// https://leetcode.com/problems/design-excel-sum-formula

/*
Design the basic function of Excel and implement the function of the sum formula.
Implement the Excel class:
Excel(int height, char width) Initializes the object with the height and the width of 
the sheet. The sheet is an integer matrix mat of size height x width with the row index 
in the range [1, height] and the column index in the range ['A', width]. All the values 
should be zero initially.
void set(int row, char column, int val) Changes the value at mat[row][column] to be val.
int get(int row, char column) Returns the value at mat[row][column].
int sum(int row, char column, List<String> numbers) Sets the value at mat[row][column] to 
be the sum of cells represented by numbers and returns the value at mat[row][column]. This 
sum formula should exist until this cell is overlapped by another value or another sum formula. 
numbers[i] could be on the format:
"ColRow" that represents a single cell.
For example, "F7" represents the cell mat[7]['F'].
"ColRow1:ColRow2" that represents a range of cells. The range will always be a rectangle where 
"ColRow1" represent the position of the top-left cell, and "ColRow2" represents the position of 
the bottom-right cell.
For example, "B3:F7" represents the cells mat[i][j] for 3 <= i <= 7 and 'B' <= j <= 'F'.
Note: You could assume that there will not be any circular sum reference.

For example, mat[1]['A'] == sum(1, "B") and mat[1]['B'] == sum(1, "A").
*/

/*1 <= height <= 26
'A' <= width <= 'Z'
1 <= row <= height
'A' <= column <= width
-100 <= val <= 100
1 <= numbers.length <= 5
numbers[i] has the format "ColRow" or "ColRow1:ColRow2".
At most 100 calls will be made to set, get, and sum.
*/
class Excel {
private:
    vector<vector<int>> mat_;
    map<pair<int, char>, vector<string>> formula_;
public:
    Excel(int H, char W) {
        formula_.clear();
        mat_ = vector<vector<int>>(H, vector<int>(W-'A'+1, 0));
    }
    
    void set(int r, char c, int val) {
        if(formula_.count({r, c})) //erase formula first.
            formula_.erase({r, c});
        mat_[r-1][c-'A'] = val;
    }
    
    int get(int r, char c) {
        if(formula_.count({r, c})) //if find formula, use formula.
            return sum(r, c, formula_[{r, c}]);
        return mat_[r-1][c-'A'];
    }
    
    int sum(int r, char c, vector<string> strs) {
        int sum = 0;
        for(string str : strs) {
            if(str.find(':') == string::npos) {
                char w = str[0];
                int h = stoi(str.substr(1));
                sum += get(h, w);
            }else {
                int pos = str.find(':');
                int w1 = str[0] - 'A';
                int h1 = stoi(str.substr(1, pos-1));
                int w2 = str[pos+1] - 'A';
                int h2 = stoi(str.substr(pos+2));
                for(int i = h1; i <= h2; i++) {
                    for(int j = w1; j <= w2; j++) {
                        sum += get(i, j+'A');
                    }
                }
            }
        }
        formula_[{r, c}] = strs;
        return sum;
    }
};
/**
 * Your Excel object will be instantiated and called as such:
 * Excel* obj = new Excel(height, width);
 * obj->set(row,column,val);
 * int param_2 = obj->get(row,column);
 * int param_3 = obj->sum(row,column,numbers);
 */