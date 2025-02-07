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
            if( i>=4 ) {
                if(distance[i-1] == distance[i-3] && distance[i] + distance[i-4] >= distance[i-2] ) //5th line meets the 1st line.
                    return true;
            };
            if( i>=5) {               //6th line crosses 1th line.
                if( distance[i-2]-distance[i-4] >= 0 && 
                    distance[i]   >= distance[i-2] - distance[i-4] && 
                    distance[i-1] >= distance[i-3] - distance[i-5] && 
                    distance[i-1] <= distance[i-3] )
                    return true;
            }
            
            i++;
        }
        return false;
    }
};