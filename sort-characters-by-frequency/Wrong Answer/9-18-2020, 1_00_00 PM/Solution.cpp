// https://leetcode.com/problems/sort-characters-by-frequency

class Solution {
public:
    string frequencySort(string s) {
        int counts[256] = {0};
        for (char ch : s)
            ++counts[ch];
        string ans;
        ans = s;
        int j=0;
        for(int i=0; i<256; i++) {
            while(counts[i]>0) {
                ans[j] = i;
                counts[i]--;
                j++;
            };
        }
        
        //sort(s.begin(), s.end(), [&](char a, char b) { 
        //    return counts[a] > counts[b] || (counts[a] == counts[b] && a < b); 
        //});
        return ans;
    }
};