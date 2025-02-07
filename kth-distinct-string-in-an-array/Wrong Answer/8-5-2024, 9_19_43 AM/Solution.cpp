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
        unordered_map<string, int> mp;  //string, idx
        vector<int> idx(sz, -1); //idx, string
        
        int count = 0;
        for(int i=0; i<sz; i++) {
            if( mp.find(arr[i]) == mp.end()) {
                mp[arr[i]] = i;
                idx[i] = i;
                count++;
            } else {
                //delete arr[i];
                idx[mp[arr[i]]] = -1;
                mp.erase(arr[i]);
                count--;
            }
        }
        if(count < k)
            return "";

        count = 0;
        for(int i=0; i<sz; i++) {
            if(idx[i] != -1)
                count++;

            if(count == k )
                return arr[i];
        }

        return "";
        
    }
};