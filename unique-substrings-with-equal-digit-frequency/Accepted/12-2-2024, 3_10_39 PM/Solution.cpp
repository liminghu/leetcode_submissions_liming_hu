// https://leetcode.com/problems/unique-substrings-with-equal-digit-frequency

class Solution {
public:
    int equalDigitFrequency(string s) {
        unordered_set<string> rets;
        int n = s.length();
        for(int i=0; i<n; i++) {
            vector<int> freq(10);
            for(int j=i; j<n; j++) {
                int idx = s[j]-'0';
                freq[idx]++;
                if(equalDigit(freq)) {
                    rets.insert(s.substr(i, j-i+1));
                }
            }
        }
        return rets.size();
    }
    bool equalDigit(vector<int>& freq) {
        int itemFreq = -1; 
        for(int i=0; i<freq.size(); i++) {
            if(freq[i] == 0 )
                continue;
            if( itemFreq == -1 )
                itemFreq = freq[i];
            if(itemFreq != freq[i])
                return false;
        }
        return true;
    }
};