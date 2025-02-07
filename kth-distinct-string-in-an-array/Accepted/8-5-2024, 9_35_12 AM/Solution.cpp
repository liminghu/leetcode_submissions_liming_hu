// https://leetcode.com/problems/kth-distinct-string-in-an-array

/*A distinct string is a string that is present only once in an array.
Given an array of strings arr, and an integer k, return the kth distinct 
string present in arr. If there are fewer than k distinct strings, return an empty string "".
Note that the strings are considered in the order in which they appear in the array.
*/
class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        int sz = arr.size();
        unordered_map<string, int> mp;  //string, count
        
        for(int i=0; i<sz; i++) {
            mp[arr[i]]++;
        }

        int count = 0;
        for(int i=0; i<sz; i++) {
            if(mp[arr[i]]== 1)
                count++;

            if(count == k )
                return arr[i];
        }

        return "";
        
    }
};