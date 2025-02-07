// https://leetcode.com/problems/relative-sort-array

/*Given two arrays arr1 and arr2, the elements of arr2 are distinct, and all elements in arr2 are also in arr1.
Sort the elements of arr1 such that the relative ordering of items in arr1 are the same as in arr2. Elements that do not appear in arr2 should be placed at the end of arr1 in ascending order.
1 <= arr1.length, arr2.length <= 1000
0 <= arr1[i], arr2[i] <= 1000
All the elements of arr2 are distinct.
Each arr2[i] is in arr1.
*/
class Solution {
public:

    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int, int> countMap; //value, count.
        for(int i=0; i<arr2.size(); i++) 
            countMap[ arr2[i] ] = 0;
        vector<int> remaining, result;
        for(int i=0; i<arr1.size(); i++) {
            if(countMap.find(arr1[i]) != countMap.end())
                countMap[ arr1[i] ]++;
            else
                remaining.push_back(arr1[i]);
        }
        sort(remaining.begin(), remaining.end());
        for(int i=0; i<arr2.size(); i++) {
            for(int j=0; j<countMap[ arr2[i] ]; j++) {
                result.push_back(arr2[i]);
            }
        };
        for(int i=0; i<remaining.size(); i++) {
            result.push_back(remaining[i]);
        };
        return result;
    }
};