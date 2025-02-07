// https://leetcode.com/problems/pascals-triangle-ii

/*
Given an integer rowIndex, return the rowIndexth (0-indexed) row of the Pascal's triangle.
In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:
Example 1:
Input: rowIndex = 3
Output: [1,3,3,1]

Example 2:
Input: rowIndex = 0
Output: [1]

Example 3:
Input: rowIndex = 1
Output: [1,1]
 

Constraints:
0 <= rowIndex <= 33
 
Follow up: Could you optimize your algorithm to use only O(rowIndex) extra space?
*/
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex == 0)
            return {1};
        if(rowIndex == 1 )
            return {1,1};
        if(rowIndex == 2 )
            return {1,2,1};
        //2, 3, 4...
        vector<int> aboveRow = getRow(rowIndex-1);   //size: rowIndex.
        //need to add 1.
        for(int i=1; i<(rowIndex+1)/2; i++) {
            int first = aboveRow[i-1];  //1    1,2,1           
            int second = aboveRow[i];   //2
            //int third = aboveRow[i+1];
            aboveRow[i] = first + second; //3
            aboveRow[rowIndex-1-(i-1)] = aboveRow[i];
        }
        aboveRow.push_back(1);
        return aboveRow;
    }
};