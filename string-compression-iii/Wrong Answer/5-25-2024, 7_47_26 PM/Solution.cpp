// https://leetcode.com/problems/string-compression-iii

class Solution {
public:
    string compressedString(string word) {
        string ans;
        string segments;
        for(int i=0; i<word.length(); i++) {
            //find the segment.
            char element = word[i];
            int count = 1;
            for(int j=i+1; j<word.length(); j++) {
                if (word[j] == element && count < 9)
                    count++;
                else
                    break;                    
            };
            string segment = "";
            segment += to_string(count)+element;
            
            
            //put it in the segments.
            segments +=segment;
        }
        return segments;
        
    }
};