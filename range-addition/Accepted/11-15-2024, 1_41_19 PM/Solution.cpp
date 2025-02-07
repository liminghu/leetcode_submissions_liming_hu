// https://leetcode.com/problems/range-addition

class Solution {
public:
    vector<int> getModifiedArray1(int length, vector<vector<int>>& updates) {
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
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> rets(length, 0);
        for(auto& update:updates) {
            int start = update[0];
            int end = update[1];
            int val = update[2];
            rets[start]+= val;
            if(end<length-1)
                rets[end+1] -= val;
        }
        for(int i=0, cur =0; i<length; i++ ) {
            cur += rets[i];
            rets[i] = cur;
        }
        return rets;
    }
};