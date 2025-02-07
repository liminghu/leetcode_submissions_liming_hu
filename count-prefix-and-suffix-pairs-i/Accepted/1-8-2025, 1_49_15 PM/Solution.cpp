// https://leetcode.com/problems/count-prefix-and-suffix-pairs-i

class Solution {
public:
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int ret = 0;
        for(int i=0; i<n-1; i++) {
            for(int j=i+1; j<n; j++) {
                if(isPrefixAndSuffix(words[i], words[j]))
                    ret++;
            }
        };
        return ret;       
    }
    bool isPrefixAndSuffix(string str1, string str2) {
        if(str1.length()> str2.length())
            return false;
        int pos = str2.find(str1);
        if(pos>0 || pos == -1)
            return false;
        reverse(str2.begin(), str2.end());
        reverse(str1.begin(), str1.end());
        pos = str2.find(str1);
        if(pos>0 || pos == -1)
            return false;
        return true;        
    }
};