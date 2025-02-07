// https://leetcode.com/problems/the-skyline-problem

/*
A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. 
Given the locations and heights of all the buildings, return the skyline formed by these buildings collectively.

The geometric information of each building is given in the array buildings where buildings[i] = [lefti, righti, heighti]:

lefti is the x coordinate of the left edge of the ith building.
righti is the x coordinate of the right edge of the ith building.
heighti is the height of the ith building.
You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

The skyline should be represented as a list of "key points" sorted by their x-coordinate in the form [[x1,y1],[x2,y2],...]. 
Each key point is the left endpoint of some horizontal segment in the skyline except the last point in the list, which always
 has a y-coordinate 0 and is used to mark the skyline's termination where the rightmost building ends. Any ground between the
  leftmost and rightmost buildings should be part of the skyline's contour.

Note: There must be no consecutive horizontal lines of equal height in the output skyline. For instance, 
[...,[2 3],[4 5],[7 5],[11 5],[12 7],...] is not acceptable; the three lines of height 5 should be merged into one in the 
final output as such: [...,[2 3],[4 5],[12 7],...]
*/
class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) { //1 <= buildings.length <= 104
                                                                    //0 <= lefti < righti <= 231 - 1
                                                                    //1 <= heighti <= 231 - 1
                                                                    //buildings is sorted by lefti in non-decreasing order.
        vector<vector<int>> ans;
        multiset<int> pq{0}; //it is sorted non decreasing.
        
        vector<pair<int, int>> points;
        
        for(auto b: buildings){
            points.push_back({b[0], -b[2]}); //entering,  height is negative.
            points.push_back({b[1], b[2]});  //leaving
        }
        
        sort(points.begin(), points.end()); //so the pints will be always entering first.
        
        int ongoingHeight = 0;
        
        // points.first = x coordinate, points.second = height
        for(int i = 0; i < points.size(); i++){
            int currentPoint = points[i].first; //x
            int heightAtCurrentPoint = points[i].second; //height, if negative entering.
            
            if(heightAtCurrentPoint < 0){
                pq.insert(-heightAtCurrentPoint); //change it to pos.
            } else {
                pq.erase(pq.find(heightAtCurrentPoint)); //leaving, delete it. if duplicates, just delete the first one.
            }
            
            // after inserting/removing heightAtI, if there's a change
            auto pqTop = *pq.rbegin(); //end. the highest.
            if(ongoingHeight != pqTop){
                ongoingHeight = pqTop;
                ans.push_back({currentPoint, ongoingHeight});
            }
        }
        
        return ans;
        
    }
};