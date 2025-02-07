// https://leetcode.com/problems/element-appearing-more-than-25-in-sorted-array

class Solution {
public:
    int findSpecialInteger(vector<int>& arr) { //sorted in non-decreasing order
        int sz = arr.size()/4;
        for(int i=0; i<arr.size()-sz; i++) {
            if(arr[i]== arr[i+sz])
                return arr[i];
        };
        return -1;
    }
};