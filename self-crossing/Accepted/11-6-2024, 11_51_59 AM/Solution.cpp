// https://leetcode.com/problems/self-crossing

class Solution {
public:
    bool isSelfCrossing(vector<int>& distance) {
        int n = distance.size();
        if(n<=3)
            return false;
        
        int i = 3;
/*               i-2
    case 1 : i-1┌─┐
                └─┼─>i
                 i-3
                 
                    i-2
    case 2 : i-1 ┌────┐
                 └─══>┘i-3
                 i  i-4      (i overlapped i-4)

    case 3 :    i-4
               ┌──┐ 
               │i<┼─┐
            i-3│ i-5│i-1
               └────┘
                i-2

*/
        while( i<n ) {
            if(distance[i] >= distance[i-2] && distance[i-1] <= distance[i-3] ) //4th line crossing.
                return true;
            if( i >= 4 ) {
                if(distance[i-1] == distance[i-3] && distance[i] + distance[i-4] >= distance[i-2] ) //5th line meets the 1st line.
                    return true;
            };
            if( i >= 5) {               //6th line crosses 1th line.
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