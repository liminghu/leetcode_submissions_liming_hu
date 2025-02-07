// https://leetcode.com/problems/minimum-index-sum-of-two-lists

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, vector<int>> dict1;
        unordered_map<string, vector<int>> dict2;
        for(int i=0; i<list1.size(); i++)
            dict1[list1[i]].push_back(i);
        for(int i=0; i<list2.size(); i++)
            dict2[list2[i]].push_back(i);
        int idx_sum = INT_MAX;
        vector<string> rets;
        for(auto item:dict1) {
            string word = item.first;
            if(dict2.find(word)==dict2.end())
                continue;
            if(item.second[0]+dict2[word][0]>idx_sum)
                continue;
            else if(item.second[0]+dict2[word][0]==idx_sum)
                rets.push_back(word);
            else {
                rets.clear();
                idx_sum = item.second[0]+dict2[word][0];
                rets.push_back(word);
            }
        }
        return rets;
    }
};