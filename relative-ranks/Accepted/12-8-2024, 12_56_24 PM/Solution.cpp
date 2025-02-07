// https://leetcode.com/problems/relative-ranks

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> result(score.size());
        vector<pair<int,int>> rankIndex(score.size());
        for(int i=0; i<rankIndex.size(); i++) {
            rankIndex[i].first = score[i];
            rankIndex[i].second = i;
        }
        sort(rankIndex.begin(), rankIndex.end(), [](pair<int,int>& a, pair<int,int>& b) {return a.first > b.first;}); //descending
        for(int i=0; i<score.size(); i++) {
            if(i==0) {
                result[rankIndex[i].second] = "Gold Medal";
            } else if(i==1) {
                result[rankIndex[i].second] = "Silver Medal";
            } else if(i==2) {
                result[rankIndex[i].second] = "Bronze Medal";
            } else {
                result[rankIndex[i].second] = to_string(i+1);
            }
        }
        return result;

    }
};