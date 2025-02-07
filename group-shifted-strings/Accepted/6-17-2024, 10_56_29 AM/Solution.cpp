// https://leetcode.com/problems/group-shifted-strings

class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) { //1 <= strings.length <= 200 1 <= strings[i].length <= 50 strings[i] consists of lowercase English letters.
        
        int sz = strings.size();
        
        unordered_map<string, vector<string>> hash;
        int diff;
        string shifted_cur;
        for(int i=0; i<sz; i++) {
            string cur = strings[i];
            shifted_cur = cur;
            //shift until the first letter is 'a'
            diff = cur[0]-'a';
            if(diff >0 ) {
                for(int j=0; j<cur.length(); j++) {
                    shifted_cur[j] = cur[j]-'a'>=diff? cur[j]-diff: cur[j]-diff+26;               
                }
            }
            hash[shifted_cur].push_back(cur);
            
        }
        
        vector<vector<string>> ans;
        
        unordered_map<string, vector<string>>::iterator it;
        for(it=hash.begin(); it!=hash.end(); it++) {
            ans.push_back(it->second);
        };
        
        return ans;
        
    }
};