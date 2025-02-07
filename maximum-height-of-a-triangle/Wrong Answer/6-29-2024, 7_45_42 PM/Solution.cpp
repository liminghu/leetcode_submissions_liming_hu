// https://leetcode.com/problems/maximum-height-of-a-triangle

class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) { //1 <= red, blue <= 100
        int max_height = 100;
        int height = 1;
        int odd = 0;
        int even = 0;
        while( odd < max(red, blue) && even < min(red, blue) ) {
            if(height % 2 != 0) {
                odd += height;
            } else {
                even += height;
            };
            height++;
        }
        return height;
        
    }
};