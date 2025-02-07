// https://leetcode.com/problems/maximum-height-of-a-triangle

class Solution {
public:
    int maxHeightOfTriangle(int red, int blue) {
        return max(Helper(blue, red), Helper(red,blue));
    }
    int Helper(int red, int blue) { //1 <= red, blue <= 100
        int height = 0;
        int i = 1;

        while(true) {
            if( i%2 ==1) {
                if(red >=i) {
                    red -= i;
                } else
                    break;
            } else {
                if(blue >= i) {
                    blue -=i;
                } else 
                    break;
            }
            height++;
            i++;
        }
        return height; 
    }
};