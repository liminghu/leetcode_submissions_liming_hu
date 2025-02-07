// https://leetcode.com/problems/largest-rectangle-in-histogram

/*Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, 
return the area of the largest rectangle in the histogram.
*/
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        /*  
            1 <= heights.length <= 105
            0 <= heights[i] <= 104
        */
        return calculateArea(heights, 0, heights.size()-1);
    }
    int calculateArea(vector<int>& heights, int start, int end) {
        if(start>end) 
            return 0;
        int minHeightIdx = start;
        for(int i=start; i<=end; i++)
            if (heights[minHeightIdx] > heights[i])
                minHeightIdx = i;
        int curArea = heights[minHeightIdx] * (end-start+1);
        int left = calculateArea(heights, start, minHeightIdx-1);
        int right = calculateArea(heights, minHeightIdx+1, end);
        return max(curArea, max(left, right));
    }
};