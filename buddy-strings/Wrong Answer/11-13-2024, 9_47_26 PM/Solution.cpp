// https://leetcode.com/problems/buddy-strings

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if(s.size()!=goal.size())
            return false;
        if(s.size()<=1 || goal.size()<=1)
            return false;
        if(s==goal) {
            vector<int> dict(26, 0);
            for(int i=0; i<s.length(); i++) {
                dict[s[i]-'a']++;
                if(dict[s[i]-'a']>=2)
                    return true;
            }
            return false;
        }
        int firstDist = 0;
        int secondDist = 0;
        for(int i=0; i<s.length(); i++) {
            if(s[i] == goal[i])
                continue;
            if(firstDist==0)
                firstDist = s[i] - goal[i];
           else if(secondDist==0) {
                secondDist = s[i] - goal[i];
                if(firstDist != -secondDist)
                    return false;
           } else {
            return false;
           }
        }
        if(firstDist == 0 || secondDist==0)
            return false;
        return true;
    }
};