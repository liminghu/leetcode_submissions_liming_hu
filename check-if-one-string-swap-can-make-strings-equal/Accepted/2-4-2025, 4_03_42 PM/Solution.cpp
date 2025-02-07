// https://leetcode.com/problems/check-if-one-string-swap-can-make-strings-equal

class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2)
            return true;
        if(s1.size() <=1)
            return false;

        pair<char, char> firstDiff;
        int first_pos = -1;
        pair<char, char> secondDiff;
        int second_pos = -1;
        for(int i=0; i<s1.size(); i++) {
            if(s1[i] == s2[i])
                continue;
            if(first_pos < 0) {
                firstDiff.first = s1[i];
                firstDiff.second = s2[i];
                first_pos = i;
            } else if(second_pos < 0) {
                secondDiff.first = s1[i];
                secondDiff.second = s2[i];
                second_pos = i;
            } else {
                return false;
            }
        }

        if(first_pos >= 0 && second_pos >=0)
            return firstDiff.first == secondDiff.second && firstDiff.second == secondDiff.first;
        
        //only first_pos > = 0 
        return false;
    }
};