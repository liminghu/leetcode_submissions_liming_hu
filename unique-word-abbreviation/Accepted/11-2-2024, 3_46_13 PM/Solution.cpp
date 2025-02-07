// https://leetcode.com/problems/unique-word-abbreviation

class ValidWordAbbr {
private:
    unordered_map<string, unordered_set<string>> mp;
public:
    ValidWordAbbr(vector<string>& dictionary) {
        for(int i=0; i<dictionary.size(); i++) {
            if(dictionary[i].size()<=2)
                mp[dictionary[i]].insert(dictionary[i]);
            string abbr;
            abbr +=dictionary[i][0];
            int count =dictionary[i].size() - 2;
            abbr += to_string(count);    
            abbr += dictionary[i][dictionary[i].size()-1];
            mp[abbr].insert(dictionary[i]);
        }
    }
    
    bool isUnique(string word) {
        string abbr;
        if(word.size()<=2)
            abbr = word;
        else {
            abbr =word[0];
            int count =word.size() -2;
            abbr += to_string(count);    
            abbr += word[word.size()-1]; 
        }
        if(mp.find(abbr) == mp.end())
            return true;
        else {
            return mp[abbr].count(word) == mp[abbr].size();
        }
        return false;
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr* obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj->isUnique(word);
 */