// https://leetcode.com/problems/set-intersection-size-at-least-two

class Solution {
public:
/** 
Taking example of [[1,3],[1,4],[2,5],[3,5]]

1) Sort them by end points, if end points match place bigger start point first use this example to understand why ([[1,3],[3,7],[5,7],[7,8]])
[[1,3],[1,4],[3,5],[2,5]]
2) Make an interval of first elements ending and ending - 1
3) Traverse the array and total 3 cases can be there:
    Case 1:
        The starting point of current interval is less than our chosen interval's start (head)
        Total overlap, move on
    Case 2:
        The starting point of current interval is less than our chosen interval's end (tail)
        Half overlap, head becomes tail, tail becomes ending of current interval's end
    Case 3:
        The starting point of current interval is greater than our chosen interval's end
        No overlap, we need to reset we again use same strategy of giving ending two points

    Diagram:
    0  1  2  3  4  5  6  7  8  9 10 11
    |--|--|--|--|--|--|--|--|--|--|--|

       |-----|
       |--------|
             |-----|
          |--------|
		  
	Initial Interval
          |--|
	   head  tail
*/

    int intersectionSizeTwo(vector<vector<int>>& intervals) { //Return the minimum possible size of a containing set.
    //A containing set is an array nums where each interval from intervals has at least two integers in nums.
        int ans=0;
        sort(intervals.begin(), intervals.end(), [](auto &l, auto &r){
            if(l[1]!=r[1])
                return l[1] < r[1];
            else 
                return l[0] > r[0];
        }); //sort increasing, by ending, then start decreasing.

        int count = 2;
        int head = intervals[0][1]-1;
        int tail = intervals[0][1]; //get the last 2 elements.

        for(auto& interval:intervals) { //sorted tail increasing, then head decreasing.
            if(interval[0] <=head) {      //Case 1:
        //The starting point of current interval is less than our chosen interval's start (head)
        //Total overlap, move on
                continue;
            } else if(interval[0] <=tail) {
                // Case 2:
        //The starting point of current interval is less than our chosen interval's end (tail)
        //Half overlap, head becomes tail, tail becomes ending of current interval's end
                head = tail;
                tail = interval[1];
                count++;
            } else {
                //Case 3:
        //The starting point of current interval is greater than our chosen interval's end
        //No overlap, we need to reset we again use same strategy of giving ending two points
                head = interval[1]-1;
                tail = interval[1];
                count +=2;
            }
        }


    return count;
        
    }
};