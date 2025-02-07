// https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor

/*
Given an array of integers arr.
We want to select three indices i, j and k where (0 <= i < j <= k < arr.length).
Let's define a and b as follows:
a = arr[i] ^ arr[i + 1] ^ ... ^ arr[j - 1]
b = arr[j] ^ arr[j + 1] ^ ... ^ arr[k]
Note that ^ denotes the bitwise-xor operation.
Return the number of triplets (i, j and k) Where a == b.
1 <= arr.length <= 300
1 <= arr[i] <= 108
*/
class Solution {
public:
    int countTriplets(vector<int>& arr) {
        unordered_map<int, vector<int>> mp; //pre_xor_sum_val -> {idx};
        mp[0].push_back(-1);

        int xorsum = 0;
        int ret = 0;
        for(int k=0; k<arr.size(); k++) {
            xorsum ^= arr[k];
            for(int i:mp[ xorsum ^ 0 ] ) {
                //xor_sum: [i+1, k] == 0
                 // j = i+2, ...k
                 ret += k-i-1;
            }
            mp[xorsum].push_back(k);
        }
        return ret;

    }
};