// https://leetcode.com/problems/longest-mountain-in-array

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int ret = 0;
        int n = arr.size();
        for(int i=1; i<n-1; i++) {
            if(arr[i-1]<arr[i] && arr[i]>arr[i+1]) { //peak;
                int left = i-1;
                int right = i+1;
                while(left>0 && arr[left-1]<arr[left])
                    left--;
                while(right<n-1 && arr[right] > arr[right+1])
                    right++; 
                ret = max(ret, right-left+1);
            }
        }

        return ret;
    }
};