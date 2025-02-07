// https://leetcode.com/problems/make-two-arrays-equal-by-reversing-subarrays

/*You are given two integer arrays of equal length target and arr. 
In one step, you can select any non-empty subarray of arr and reverse it. 
You are allowed to make any number of steps.
Return true if you can make arr equal to target or false otherwise.
*/
class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        /*  target.length == arr.length
            1 <= target.length <= 1000
            1 <= target[i] <= 1000
            1 <= arr[i] <= 1000
        */
        sort(target.begin(), target.end());
        sort(arr.begin(), arr.end());
        int sz = target.size();
        for(int i=0; i<sz; i++) {
            if(target[i]!=arr[i])
                return false;
        }

        return true;
    }
};