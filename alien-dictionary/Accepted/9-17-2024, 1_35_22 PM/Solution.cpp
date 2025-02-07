// https://leetcode.com/problems/alien-dictionary

/*
There is a new alien language that uses the English alphabet. However, the order of the letters is unknown to you.
You are given a list of strings words from the alien language's dictionary. Now it is claimed that the strings in words are 
sorted lexicographically
 by the rules of this new language.
If this claim is incorrect, and the given arrangement of string in words cannot correspond to any order of letters, return "".
Otherwise, return a string of the unique letters in the new alien language sorted in lexicographically increasing order by 
the new language's rules. If there are multiple solutions, return any of them.
*/
class Solution {
public:
    string alienOrder(vector<string>& words) {
        unordered_map<char, unordered_set<char>> next;
        unordered_map<char, int> inDegree;
        for(auto word: words) {
            for(auto ch: word) { //initialize all the chars inDegree: 0
                inDegree[ch] = 0;
            }
        }
        for(int i=0; i<words.size()-1; i++) {
            string s = words[i];
            string t = words[i+1];
            //if s contains t, sth wrong
            //ab 
            //a
            if(s.size()>t.size()  &&  s.substr(0, t.size()) == t ) 
                return "";
            for(int j=0; j<min(s.size(), t.size()); j++) {
                if(s[j] == t[j] )
                    continue;
                if(next[ s[j] ].find( t[j] ) == next[ s[j] ].end()) { //t[j] was not s[j]'s next before.
                    next[ s[j] ].insert( t[j] );
                    inDegree[ t[j] ]++;
                }
                break;
            }
        }
        queue<int> q;
        for(auto x: inDegree) {
            if(x.second == 0)
                q.push(x.first);
        }
        string ret;
        while(!q.empty()) {
            char cur = q.front();
            q.pop();
            ret.push_back(cur);
            for(auto next: next[cur]) {
                inDegree[next]--;
                if(inDegree[next] == 0)
                    q.push(next);
            }
        }
        if(ret.size() != inDegree.size())
            return "";
        else
            return ret;
    }
};