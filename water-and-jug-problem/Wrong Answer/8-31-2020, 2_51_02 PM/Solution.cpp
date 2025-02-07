// https://leetcode.com/problems/water-and-jug-problem

class Solution {
public:
    bool canMeasureWater(int x, int y, int z) {
        if (z>x+y) return false;
        if(x==0 ) return y==z;
        if(y==0) return x==z;
        return z % gcd(x,y)==0;
        
    }
};