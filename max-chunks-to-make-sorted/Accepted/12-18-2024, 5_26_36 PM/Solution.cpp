// https://leetcode.com/problems/max-chunks-to-make-sorted

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n = arr.size();
        int chunks = 0;
        int maxNum = 0;
        for(int i=0; i<n; i++) {
            maxNum = max(maxNum, arr[i]);
            if(maxNum == i)
                chunks++;
        } 
        return chunks;
    }
};