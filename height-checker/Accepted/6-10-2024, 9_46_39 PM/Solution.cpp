// https://leetcode.com/problems/height-checker

class Solution {
public:
/*
    A school is trying to take an annual photo of all the students. The students are asked to stand in a single file line in non-decreasing order by height. 
    Let this ordering be represented by the integer array expected where expected[i] is the expected height of the ith student in line.
    You are given an integer array heights representing the current order that the students are standing in. Each heights[i] is the height of the ith student in line (0-indexed).
    Return the number of indices where heights[i] != expected[i].
*/
    int heightChecker(vector<int>& heights) { //1 <= heights[i] <= 100; 1 <= heights.length <= 100
        int ans=0;
        vector<int> sorted_heights = heights;
            sort(sorted_heights.begin(), sorted_heights.end()); //sorted non-decreasing.
        int n = heights.size();
        for(int i=0; i<n; i++) {
            if(sorted_heights[i]!=heights[i])
                ans++;
        };
        return ans;
        
    }
};