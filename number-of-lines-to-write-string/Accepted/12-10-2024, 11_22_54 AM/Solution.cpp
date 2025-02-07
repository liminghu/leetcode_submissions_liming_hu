// https://leetcode.com/problems/number-of-lines-to-write-string

class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines = 0;
        int lastPixels = 0; //no longer than 100 pixels.
        int i=0;
        while(i<s.length()) {
            int curPixels = 0;
            while(i<s.length() && curPixels+widths[s[i]-'a']<=100) {
                curPixels += widths[s[i]-'a'];
                i++;
            }
            lines++;
            lastPixels = curPixels;
        }

        return {lines, lastPixels};
    }
};