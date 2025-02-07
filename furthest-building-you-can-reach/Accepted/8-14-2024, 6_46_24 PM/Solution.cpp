// https://leetcode.com/problems/furthest-building-you-can-reach

/*You are given an integer array heights representing the heights of buildings, some bricks, and some ladders.

You start your journey from building 0 and move to the next building by possibly using bricks or ladders.

While moving from building i to building i+1 (0-indexed),

If the current building's height is greater than or equal to the next building's height, you do not need a ladder or bricks.
If the current building's height is less than the next building's height, you can either use one ladder or (h[i+1] - h[i]) bricks.
Return the furthest building index (0-indexed) you can reach if you use the given ladders and bricks optimally.
*/
class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int n = heights.size();
        multiset<int> s;
        int count = 0;
        for(int i=1; i<n; i++) {
            int diff = heights[i] - heights[i-1];
            if( diff <= 0 ) 
                continue;

            if(s.size() < ladders) {
                s.insert(diff);
            } else { //ladders posDiff.
                s.insert(diff);
                if(bricks < *s.begin())
                    return i-1;
                bricks -= *s.begin();
                s.erase(s.begin());
            }           
        }

        return n-1;

        /*int n = heights.size();
        priority_queue<int, vector<int>, greater<>> posDiff; //diff,  min.      size: ladders+1.

        //int res = 0;
        for(int i=1; i<n; i++) {
            int diff = heights[i] - heights[i-1];
            if( diff <= 0 ) 
                continue;

            if(posDiff.size() < ladders) {
                posDiff.push(diff);
            } else { //ladders posDiff.
                posDiff.push(diff);
                if(bricks < posDiff.top())
                    return i-1;
                bricks -= posDiff.top();
                posDiff.pop();
            }           
        }

        return n-1;*/
    }
};