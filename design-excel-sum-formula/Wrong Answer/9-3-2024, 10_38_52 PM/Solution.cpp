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
    int height_;
    char width_;
    vector<vector<int>> matrix_;
    unordered_map<string, vector<string>> mp; //pair<int, char>, formula
    unordered_map<string, vector<string>> mp_dependant; //char, vector<char>

public:
    Excel(int height, char width) {
        height_ = height;
        width_ = width;
        vector<vector<int>> matrix(height, vector<int>(width-'A'+1, 0));
        matrix_ = matrix;   
        mp.clear();
    }
    
    void set(int row, char column, int val) {
        matrix_[row-1][column-'A'] = val;  
        string key = column + to_string(row);
        if(mp_dependant.find(key)!=mp_dependant.end()) {
           vector<string> cells =  mp_dependant[key];
            for(int i=0; i<cells.size(); i++) {
                string formula_i = cells[i];
                char column_i = formula_i[0];
                int row_i = 0;
                for(int j=1; j<formula_i.length(); j++) {
                    row_i = row_i*10 + formula_i[j]-'0';
                };
                get(row_i, column_i);
            }
        }
    }
    
    int get(int row, char column) {
        string key = column + to_string(row);
        //cout << "key = " << key << " val "<<  matrix_[row-1][column-'A'] << endl;
        if(mp.find(key) == mp.end()) //no formula
            return matrix_[row-1][column-'A'];     
        else {

            return sum(row, column, mp[key]);   
        }
    }
    
    int sum(int row, char column, vector<string> numbers) {
        /*be the sum of cells represented by numbers and returns the value at mat[row][column]. 
        This sum formula should exist until this cell is overlapped by another value or another 
        sum formula. numbers[i] could be on the format:*/

        /*
        "ColRow" that represents a single cell.
        For example, "F7" represents the cell mat[7]['F'].
        "ColRow1:ColRow2" that represents a range of cells. The range will always be a rectangle 
        where "ColRow1" represent the position of the top-left cell, and "ColRow2" represents the position of the bottom-right cell.
        For example, "B3:F7" represents the cells mat[i][j] for 3 <= i <= 7 and 'B' <= j <= 'F'.
        */
        int ret = 0;
        string key = column + to_string(row);
        mp[key] = numbers;
        for(int i=0; i<numbers.size(); i++) {
            string formula_i = numbers[i];
            int div_pos = formula_i.find(':');
            //cout << "formula_i= " << formula_i << endl;
            //cout << "div_pos = " << div_pos << endl;
            if(div_pos != -1) { //found ':'
                string start = formula_i.substr(0, div_pos);
                //cout << "formula_i start= " << start << endl;
                char column_i_start = start[0];
                int row_i_start = 0;
                for(int i=1; i<start.length(); i++) {
                    row_i_start = row_i_start*10 + start[i]-'0';
                };


                string end = formula_i.substr(div_pos+1);
                //cout << "formula_i end= " << end << endl;
                char column_i_end = end[0];
                int row_i_end = 0;
                for(int i=1; i<end.length(); i++) {
                    row_i_end = row_i_end*10 + end[i]-'0';
                };

                int cell_sum = 0;
                //cout << "row_start " << row_i_start << " row end " <<  row_i_end << endl;
                //cout << "col_start " << column_i_start << " col end " <<  column_i_end << endl;
                for(char c=column_i_start; c<=column_i_end; c++) {
                    for(int r =row_i_start; r <=row_i_end; r++ ) {
                        cell_sum += get(r, c);
                    }
                }
                //cout << "cell sum: " << cell_sum << endl;
                ret += cell_sum;

            } else {
                //formula_i    A26
                char column_i = formula_i[0];
                int row_i = 0;
                for(int i=1; i<formula_i.length(); i++) {
                    row_i = row_i*10 + formula_i[i]-'0';
                };
                ret += get(row_i, column_i);
            }
        }
        set(row, column, ret);
        return ret;  
    }
};

/**
 * Your Excel object will be instantiated and called as such:
 * Excel* obj = new Excel(height, width);
 * obj->set(row,column,val);
 * int param_2 = obj->get(row,column);
 * int param_3 = obj->sum(row,column,numbers);
 */