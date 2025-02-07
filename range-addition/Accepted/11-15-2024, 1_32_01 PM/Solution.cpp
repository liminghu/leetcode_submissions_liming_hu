// https://leetcode.com/problems/range-addition

class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        //an integer length and an array updates where updates[i] = [startIdxi, endIdxi, inci].
        /*
        You have an array arr of length length with all zeros, and you have some operation to apply on arr. 
        In the ith operation, you should increment all the elements arr[startIdxi], arr[startIdxi + 1], ..., arr[endIdxi] by inci.
        Return arr after applying all the updates.
        */
        vector<int> rets(length, 0);
        for(int i=0; i<updates.size(); i++) {
            int startIdxi = updates[i][0];
            int endIdxi   = updates[i][1];
            int inci      = updates[i][2];
            for(int j=startIdxi; j<=endIdxi; j++) 
                rets[j] += inci;
        }
        return rets;
    }
};