// https://leetcode.com/problems/snakes-and-ladders

/*
You are given an n x n integer matrix board where the cells are labeled from 1 to n2 in a Boustrophedon style starting from the 
bottom left of the board (i.e. board[n - 1][0]) and alternating direction each row.

You start on square 1 of the board. In each move, starting from square curr, do the following:

Choose a destination square next with a label in the range [curr + 1, min(curr + 6, n2)].
This choice simulates the result of a standard 6-sided die roll: i.e., there are always at most 6 destinations, regardless 
of the size of the board.
If next has a snake or ladder, you must move to the destination of that snake or ladder. Otherwise, you move to next.
The game ends when you reach the square n2.
A board square on row r and column c has a snake or ladder if board[r][c] != -1. The destination of that snake or ladder is 
board[r][c]. Squares 1 and n2 are not the starting points of any snake or ladder.

Note that you only take a snake or ladder at most once per move. If the destination to a snake or ladder is the start of 
another snake or ladder, you do not follow the subsequent snake or ladder.

For example, suppose the board is [[-1,4],[-1,3]], and on the first move, your destination square is 2. You follow the ladder
 to square 3, but do not follow the subsequent ladder to 4.
Return the least number of moves required to reach the square n2. If it is not possible to reach the square, return -1.
n == board.length == board[i].length
2 <= n <= 20
board[i][j] is either -1 or in the range [1, n2].
The squares labeled 1 and n2 are not the starting points of any snake or ladder.
*/
class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        //n>=2      4
        if(board.size()==0)
            return 0;
        int n = board.size();
        vector<bool> visited( n*n + 1, false);
        int res = n*n;
        queue<int> q;
        int start = 1;
        q.push(start);
        int moves = 0;
        while(!q.empty()) {
            int size = q.size();
            for(int i=0; i<size; i++) {
                int cur = q.front();
                q.pop();
                if( cur == n*n )
                    res = min(res, moves);
                
                for(int j=1; j<=6; j++) {
                    int num = cur + j;
                    if(num > n*n )
                        break;
                    if(!visited[num]) {
                        visited[num] = true;
                        //get row, col.
                        int row = 0;
                        int col = 0;
                        getRowCol(num, n, row, col);
                        cout << "row: "<< row << " col " << col << endl; 
                        if(board[row][col] == cur )
                            continue;
                        if(board[row][col]==-1) 
                            q.push(num);
                        else 
                            q.push(board[row][col]);                        
                    }
                }    
            }
            moves++;
        }
        return res == n*n ? -1: res;
    }
    
    void getRowCol(int num, int n, int& row, int& col) {
        row = n-1 - (num-1) / n;  //  6 - 1/6    6-1- 35/6 = 0           6-1 -7/6 = 5-1 =4;        6-1 - 12/6 = 4 
        //if(row == n-1, n-3...)
        if( (n-row)%2 == 1 )  //n-1, n-3,... left to right...
            col = (num-1) % n;    //1 ,2,3,4,5,6
        else
            col = (n-1) - (num-1) % n; //right to left.
    };
};