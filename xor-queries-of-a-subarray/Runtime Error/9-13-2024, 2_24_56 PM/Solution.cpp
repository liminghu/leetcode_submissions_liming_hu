// https://leetcode.com/problems/xor-queries-of-a-subarray

/*XOR Queries of a Subarray
You are given an array arr of positive integers. You are also given the array queries where queries[i] = [lefti, righti].
For each query i compute the XOR of elements from lefti to righti (that is, arr[lefti] XOR arr[lefti + 1] XOR ... XOR arr[righti] ).
Return an array answer where answer[i] is the answer to the ith query.
1 <= arr.length, queries.length <= 3 * 104
1 <= arr[i] <= 109
queries[i].length == 2
0 <= lefti <= righti < arr.length
*/
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // a ^ a = 0
        // a ^ 0 = a
        // a ^ b = c -> a = c ^ b
        // a ^ b ^ c = a ^ (b ^ c)
        vector<int> prefXOR;
        prefXOR.push_back(0);
        for(int i=0; i<arr.size(); i++) {
            prefXOR.push_back(prefXOR[i] ^ arr[i]);
        };
        
        vector<int> ans(arr.size(), 0);
        for(int i=0; i<queries.size(); i++) {
            int l = queries[i][0];
            int r = queries[i][1];
            ans[i] = prefXOR[l]  ^ prefXOR[r+1];
        }
        return ans;
    }
};