// https://leetcode.com/problems/interval-list-intersections

/*You are given two lists of closed intervals, firstList and secondList, where firstList[i] = [starti, endi] 
and secondList[j] = [startj, endj]. Each list of intervals is pairwise disjoint and in sorted order.
Return the intersection of these two interval lists.
A closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.
The intersection of two closed intervals is a set of real numbers that are either empty or represented as a 
closed interval. For example, the intersection of [1, 3] and [2, 4] is [2, 3].
*/
class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& firstList, vector<vector<int>>& secondList) {
        int i = 0;
        int j = 0;
        vector<vector<int>> ans;
        while( i< firstList.size() && j < secondList.size()) {
            int start = max(firstList[i][0], secondList[j][0]);
            int end = min(firstList[i][1], secondList[j][1]);

            if(start<=end) 
                ans.push_back({start,end});
            
            if(firstList[i][1] < secondList[j][1])
                i++;
            else 
                j++;
        }
        return ans;
    }
};