// https://leetcode.com/problems/count-items-matching-a-rule

class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        //each items[i] = [typei, colori, namei] describes the type, color, and name of the ith item
        /*ruleKey == "type" and ruleValue == typei.
         ruleKey == "color" and ruleValue == colori.
         ruleKey == "name" and ruleValue == namei.
         Return the number of items that match the given rule.
        */
        int ret = 0;
        for(int i=0; i<items.size(); i++) {
            string typei, colori, namei;
            typei = items[i][0];
            colori = items[i][1];
            namei = items[i][2];
            if( ruleKey == "type" && ruleValue == typei ||
                ruleKey == "color" and ruleValue == colori ||
                ruleKey == "name" and ruleValue == namei )
                ret++;
        }
        return ret;
    }
};