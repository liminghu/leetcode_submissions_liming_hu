// https://leetcode.com/problems/maximum-number-of-potholes-that-can-be-fixed

class Solution {
public:
    int maxPotholes(string road, int budget) {
        //repair n consecutive potholes for a price of n + 1.
        int ret = 0;
        priority_queue<int, vector<int>> holes; //max
        int i=0;
        while(i<road.length()) {
            if(road[i]=='.')
                i++;
            else {
                int j = i;
                while(j<road.length() && road[j]=='x')
                    j++;
                holes.push(j-i);
                i=j;
            }
        }
        while(!holes.empty() && budget > 0) {
            int cur = holes.top();
            holes.pop();
            if(cur+1 <= budget) {
                ret += cur;
                budget -= (cur+1);
            } else {
                cur = cur - budget -1;
                ret += budget -1;
                budget = 0;
                break;
            }
            i++;
        };

        return ret;
    }
};