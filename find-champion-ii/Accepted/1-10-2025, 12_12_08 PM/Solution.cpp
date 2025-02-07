// https://leetcode.com/problems/find-champion-ii

class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        int m = edges.size(); //edges[i] = [ui, vi]   ui is stronger than vi
        vector<int> inDegree(n, 0);
        for(auto& edge:edges) {
            int a = edge[0], b = edge[1];
            inDegree[b]++;
        };
        int champ = -1;
        int champCount = 0;
        for(int i=0; i<n; i++) {
            if(inDegree[i]==0) {
                champCount++;
                champ = i;
            }
        }
        return champCount==1? champ: -1;
    }
};