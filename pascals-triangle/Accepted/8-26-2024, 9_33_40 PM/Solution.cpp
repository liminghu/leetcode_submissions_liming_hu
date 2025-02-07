// https://leetcode.com/problems/pascals-triangle

/*
Given an integer numRows, return the first numRows of Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
*/
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> rets;
        for(int i=0; i<numRows; i++) {
            //num of elements per row: i+1;
            vector<int> temp(i+1, 0);
            temp[0] = 1;
            temp[i] = 1;
            for(int j=1; j<i; j++) {
                temp[j] = rets[i-1][j-1]+rets[i-1][j];
            };
            rets.push_back(temp);
        }

        return rets;
    }
};