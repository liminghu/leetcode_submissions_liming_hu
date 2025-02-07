// https://leetcode.com/problems/perfect-rectangle

/*
Given an array rectangles where rectangles[i] = [xi, yi, ai, bi] 
represents an axis-aligned rectangle. The bottom-left point of the 
rectangle is (xi, yi) and the top-right point of it is (ai, bi).
Return true if all the rectangles together form an exact cover of 
a rectangular region.
1 <= rectangles.length <= 2 * 104
rectangles[i].length == 4
-105 <= xi < ai <= 105
-105 <= yi < bi <= 105
*/
class Solution {
public:
    bool isRectangleCover(vector<vector<int>>& rectangles) {
        //[xi, yi, ai, bi] 
        //bottom left: (xi, yi)
        //top-right point of it is (ai, bi)
        int x1 = INT_MAX; //(x1, y1) bottom left
        int x2 = INT_MIN; //(x2, y2) top right.
        int y1 = INT_MAX;
        int y2 = INT_MIN;        
        unordered_set<string> Set;
        int area = 0;
        for(auto rectangle: rectangles) {
            int x1i = rectangle[0];
            int y1i = rectangle[1];
            int x2i = rectangle[2];
            int y2i = rectangle[3];                                    
            x1 = min(x1i, x1);
            y1 = min(y1i, y1);
            x2 = max(x2i, x2);
            y2 = max(y2i, y2);    

            area += (x2i - x1i) * (y2i - y1i);
            string b_li = to_string(x1i) + " " + to_string(y1i);
            string t_li = to_string(x1i) + " " + to_string(y2i);
            string t_ri = to_string(x2i) + " " + to_string(y2i);
            string b_ri = to_string(x2i) + " " + to_string(y1i);
            //count of all the points should be even, and that of all the four corner points should be one
            if(Set.find(b_li) != Set.end())
                Set.erase(b_li);
            else
                Set.insert(b_li);

            if(Set.find(t_li) != Set.end())
                Set.erase(t_li);
            else
                Set.insert(t_li);

            if(Set.find(t_ri) != Set.end())
                Set.erase(t_ri);
            else
                Set.insert(t_ri);

            if(Set.find(b_ri) != Set.end())
                Set.erase(b_ri); 
            else
                Set.insert(b_ri);         
        };

        string b_l = to_string(x1) + " " + to_string(y1);
        string t_l = to_string(x1) + " " + to_string(y2);
        string t_r = to_string(x2) + " " + to_string(y2);
        string b_r = to_string(x2) + " " + to_string(y1);
  
        if(Set.find(b_l) == Set.end() || Set.find(t_l) == Set.end() || Set.find(t_r) == Set.end() || Set.find(b_r) == Set.end() || Set.size() != 4 )
            return false;
        //cout << "before area" << endl;
        return area == (x2-x1)*(y2-y1);
    }
};