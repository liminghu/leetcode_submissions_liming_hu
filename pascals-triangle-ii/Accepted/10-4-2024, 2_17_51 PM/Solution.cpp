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
        if(rowIndex == 1)
            return {1,1};
        //2, 3, 4...
        vector<int> aboveRow = getRow(rowIndex-1);   //size: rowIndex.
        //need to add 1.
        int first = 1;
        int second = 0;
        for(int i=1; i<=(rowIndex+1)/2; i++) { //(rowIndex+1)/2: 2
            cout << "i: " << i << endl;   
            second = aboveRow[i];   //3
            cout << first << " " << second << endl;
            if( i < rowIndex-1-(i-1) ) {
                aboveRow[i] = first + second; //4
                aboveRow[rowIndex-1-(i-1)] = aboveRow[i]; //4
            } else if(rowIndex %2 == 0) {  //even
                aboveRow[i] = second + second;
            }
            first = second;
        }
        aboveRow.push_back(1);
        return aboveRow;
    }
};