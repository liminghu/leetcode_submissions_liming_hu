// https://leetcode.com/problems/word-pattern

class Solution {
public:
    bool wordPattern(string pattern, string s) { 
    //s contains only lowercase English letters and spaces ' ';
    // s does not contain any leading or trailing spaces.
    //All the words in s are separated by a single space.

    unordered_map<char, string> dict_p;
     unordered_map<string, char> dict_s;
    stringstream io(s);
    string word_i;
    vector<string> v_string;
    while( io >> word_i) {
        v_string.push_back(word_i);
    }
           
    for(int i=0; i<pattern.length(); i++) {    
         if(dict_p.find(pattern[i])== dict_p.end() && dict_s.find(v_string[i])== dict_s.end()) {
            dict_p[pattern[i]] = v_string[i];
            dict_s[v_string[i]] = pattern[i];
        }
    }

    string pattern2 = "";
    for(int i=0; i<v_string.size(); i++) {
        if(dict_s.find(v_string[i])!=dict_s.end()) {
            pattern2.push_back(dict_s[v_string[i]]);
        }
    }
    return pattern == pattern2;
        
    }
};