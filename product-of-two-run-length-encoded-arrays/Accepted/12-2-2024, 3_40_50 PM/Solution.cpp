// https://leetcode.com/problems/product-of-two-run-length-encoded-arrays

class Solution {
public:
    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
        vector<vector<int>> rets;
        int prevMulti = 0;
        int i = 0;
        int j = 0;
        while( i<encoded1.size() && j < encoded2.size()) {
            int cnt1 = encoded1[i][1];
            int cnt2 = encoded2[j][1];
            int mincnt = min(cnt1, cnt2);
            int prod = encoded1[i][0] * encoded2[j][0];
            if(prevMulti == prod && rets.size() > 0) 
                rets[rets.size()-1][1] += mincnt;
            else 
                rets.push_back({prod, mincnt});
            prevMulti = prod;
            encoded1[i][1]-= mincnt;
            encoded2[j][1]-= mincnt;
            if(encoded1[i][1]==0)
                i++;
            if(encoded2[j][1]==0)
                j++;                
        }
        return rets;
    }
/*    vector<vector<int>> findRLEArray(vector<vector<int>>& encoded1, vector<vector<int>>& encoded2) {
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
    }*/
};