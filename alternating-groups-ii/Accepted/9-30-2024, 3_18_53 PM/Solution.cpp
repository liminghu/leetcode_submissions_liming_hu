// https://leetcode.com/problems/alternating-groups-ii

/*
There is a circle of red and blue tiles. You are given an array of integers colors and an integer k. The color of tile i is represented by colors[i]:
colors[i] == 0 means that tile i is red.
colors[i] == 1 means that tile i is blue.
An alternating group is every k contiguous tiles in the circle with alternating colors (each tile in the group except the first and last 
one has a different color from its left and right tiles).
Return the number of alternating groups.
Note that since colors represents a circle, the first and the last tiles are considered to be next to each other.

3 <= colors.length <= 105
0 <= colors[i] <= 1
3 <= k <= colors.length
*/
class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) { //3 <= colors.length <= 105; 0 <= colors[i] <= 1; 3 <= k <= colors.length
       unsigned int n = colors.size();
        if( n < k )
            return 0;
        vector<int> circle_colors = colors;
        circle_colors.insert( circle_colors.end(), colors.begin(), colors.end() );
        
        int count = 0;
        int streak = 1;
        for(int i=1; i<=n-1+k-1; i++) {
            if(circle_colors[i] != circle_colors[i-1])
                streak++;
            else
                streak = 1;
            if(streak >= k )
                count++;
        }
        
        return count;        
    }
};