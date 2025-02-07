// https://leetcode.com/problems/self-crossing

class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        int n = distance.size();
        if(n<=3)
            return false;
        
        int i = 3;
        while(i<n) {
            if(distance[i] >=distance[i-2] && distance[i-1] <= distance[i-3] ) //4th line crossing.
                return true;
            i++;
        }
        return false;
    }
};