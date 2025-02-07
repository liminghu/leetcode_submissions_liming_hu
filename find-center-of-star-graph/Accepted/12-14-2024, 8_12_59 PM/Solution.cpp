// https://leetcode.com/problems/find-center-of-star-graph

class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        //edges[i] = [ui, vi]
        int n = edges.size();
        unordered_set<int> st;
        for(int i=0; i<n; i++) {
            if(st.find(edges[i][0]) == st.end())
                st.insert(edges[i][0]);
            else
                return edges[i][0];

            if(st.find(edges[i][1]) == st.end())
                st.insert(edges[i][1]);
            else
                return edges[i][1];
        };
        return 0;
    }
};