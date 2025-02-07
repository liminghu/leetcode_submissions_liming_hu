// https://leetcode.com/problems/maximum-product-of-word-lengths

class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        vector<int> value(n, 0);
        for(int i=0; i<n; i++) {
            string tmp = words[i];
            for(int j=0; j<tmp.length(); j++) 
                value[i] |= ( 1 << (tmp[j]-'a') );
        }

        int ret = 0;
        for(int i=0; i<n; i++) {
            for(int j=i+1; j<n; j++) {
                if((value[i] & value[j]) != 0)
                    continue;
                int cur_prod = words[i].length() * words[j].length();
                ret = max(ret, cur_prod);
            }
        }
        return ret;
    }
};