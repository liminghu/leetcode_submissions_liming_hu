// https://leetcode.com/problems/product-of-two-run-length-encoded-arrays

class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        vector<int> decoded1 = decode(encoded1);
        vector<int> decoded2 = decode(encoded2);
        vector<int> prod;
        for(int i=0; i<decoded1.size(); i++)
            prod.push_back(decoded1[i]*decoded2[i]);
        return encode(prod);
    }
    vector<int> decode(vector<vector<int>>& encoded) {
        vector<int> rets;
        for(auto item:encoded) {
            int val = item[0];
            int freq = item[1];
            while(freq--)
                rets.push_back(val); 
        };
        return rets;
    }
    vector<vector<int>> encode(vector<int>& arr) {
        vector<vector<int>> rets;
        int i=0;
        while(i<arr.size()) {
            int val = arr[i];
            int j=i;
            while(j<arr.size() && arr[j] == val)
                j++;
            int freq = j-i;
            rets.push_back({val, freq}); 
            i = j;
        };
        return rets;
    }
};