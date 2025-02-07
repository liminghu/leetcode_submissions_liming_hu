// https://leetcode.com/problems/three-consecutive-odds

/*Given an integer array arr, return true if there are three consecutive odd numbers in the array. Otherwise, return false.
*/
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        bool res = false;
        int sz = arr.size();
        if( sz < 3 )
            return false;
     
        for(int i=0; i<sz-2; i++) {
            if(arr[i] % 2 == 0)
                continue;
            if(arr[i+1] % 2 == 0) {
                i++;
                continue;
            }
                
            if(arr[i+2] % 2 == 0) {
                i +=2;
                continue;  
            }

            if(arr[i] % 2 == 1 && arr[i+1] % 2 == 1 && arr[i+2] % 2 == 1)
                return true;
        }
        return false;

    }
};