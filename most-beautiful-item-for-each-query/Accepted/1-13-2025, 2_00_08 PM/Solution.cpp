// https://leetcode.com/problems/most-beautiful-item-for-each-query

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        //items[i] = [pricei, beautyi] denotes the price and beauty of an item respectively.
        //For each queries[j], you want to determine the maximum beauty of an item whose price is less than or equal to 
        //queries[j]. If no such item exists, then the answer to this query is 0.
        vector<int> ans(queries.size(), 0);
        sort(items.begin(), items.end());
        vector<vector<int>> queiresWithIdx(queries.size(), vector<int>(2));
        for(int i=0; i<queries.size(); i++) {
            queiresWithIdx[i][0] = queries[i];
            queiresWithIdx[i][1] = i;
        }
        sort(queiresWithIdx.begin(), queiresWithIdx.end());
        int itemIdx = 0;
        int maxBeautity = 0;
        for(int i=0; i<queries.size(); i++) { //price is increasing...
            int query = queiresWithIdx[i][0];
            int originalIdx = queiresWithIdx[i][1];
            while(itemIdx <items.size() && items[itemIdx][0]<=query) {
                maxBeautity = max(maxBeautity, items[itemIdx][1]);
                itemIdx++; 
            }
            ans[originalIdx] = maxBeautity;
        }
        return ans;
    }
};