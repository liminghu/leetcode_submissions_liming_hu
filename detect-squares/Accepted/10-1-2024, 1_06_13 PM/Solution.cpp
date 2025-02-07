// https://leetcode.com/problems/detect-squares

/*
You are given a stream of points on the X-Y plane. Design an algorithm that:
Adds new points from the stream into a data structure. Duplicate points are allowed and should be
 treated as different points.
Given a query point, counts the number of ways to choose three points from the data structure such 
that the three points and the query point form an axis-aligned square with positive area.
An axis-aligned square is a square whose edges are all the same length and are either parallel or 
perpendicular to the x-axis and y-axis.

Implement the DetectSquares class:
DetectSquares() Initializes the object with an empty data structure.
void add(int[] point) Adds a new point point = [x, y] to the data structure.
int count(int[] point) Counts the number of ways to form axis-aligned squares with point point = [x, y] 
as described above.
point.length == 2
0 <= x, y <= 1000
At most 3000 calls in total will be made to add and count.
*/
class DetectSquares {
    unordered_map<int,int> count_xy;
    vector<pair<int,int>> points; //could have duplicates.
public:
    DetectSquares() {
        
    }
    
    void add(vector<int> point) {
        int x = point[0];
        int y = point[1];
        int num = x * 1024 + y;
        count_xy[num]++;
        points.push_back({x,y});
    }
    
    int count(vector<int> point) {
        int x1 = point[0];
        int y1 = point[1];
        int ans = 0;
        for(auto& [x2, y2]: points ) {
            if( abs(y1-y2)==0 || abs(x1-x2)==0 || abs(x1-x2) != abs(y1-y2))   //only check diagonal points.
                continue; //skip empty square, or invalid rectangles.
            int x1_y2 = x1 * 1024 + y2;
            int x2_y1 = x2 * 1024 + y1;
            ans +=  count_xy[x2_y1] * count_xy[x1_y2];
        }
        return ans;

    }
};

/**
 * Your DetectSquares object will be instantiated and called as such:
 * DetectSquares* obj = new DetectSquares();
 * obj->add(point);
 * int param_2 = obj->count(point);
 */