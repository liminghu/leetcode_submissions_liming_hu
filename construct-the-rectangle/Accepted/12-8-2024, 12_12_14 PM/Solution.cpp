// https://leetcode.com/problems/construct-the-rectangle

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int st = sqrt(area);
        if(st*st == area) 
            return {st, st};
        int W = st;
        while(W>0) {
            if(area%W == 0)
                return {area/W, W};
            W--;
        }
        return {area, 1};
    }
};