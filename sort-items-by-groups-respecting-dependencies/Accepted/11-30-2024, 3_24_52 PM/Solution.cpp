// https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies

class Solution {
public:
    vector<int> sortItems(int n, int m, vector<int>& group, vector<vector<int>>& beforeItems) {
        int nextGroupId = m;
        unordered_map<int, unordered_set<int>> groupItems;
        for(int i=0; i<n; i++) {
            if(group[i]==-1) {
                group[i] = nextGroupId;
                nextGroupId++;
            }
            groupItems[group[i]].insert(i);
        }        
        unordered_map<int, unordered_set<int>> next;
        unordered_map<int,int> inDegree;
        //build graph inside each grp.
        for(int i=0; i<n; i++) {
            for(int j:beforeItems[i]) {
                //j->i
                if(group[j]!=group[i])
                    continue;
                next[j].insert(i);
                inDegree[i]++;
            }
        }

        unordered_map<int, vector<int>> groupItemsOrdered;
        for(auto x:groupItems) {
            int groupId = x.first;
            groupItemsOrdered[groupId] = topologySort(groupItems[groupId], next, inDegree);
            if(groupItemsOrdered[groupId].size() != groupItems[groupId].size())
                return {};
        }

        next.clear();
        inDegree.clear();
        //build graph among groups
        for(int i=0; i<n; i++) {
            for(int j:beforeItems[i]) {
                if(group[i]==group[j])
                    continue;
                if(next[group[j]].find(group[i])==next[group[j]].end()) {
                    next[group[j]].insert(group[i]);
                    inDegree[group[i]]++;
                }
            }
        }
        unordered_set<int> groupIds;
        for(int i=0; i<n; i++)
            groupIds.insert(group[i]);
        vector<int> groupsOrdered = topologySort(groupIds, next, inDegree);
        vector<int> rets;
        for(auto groupId:groupsOrdered) {
            for(auto node: groupItemsOrdered[groupId])
                rets.push_back(node);
        }
        return rets;
    }
    vector<int> topologySort(unordered_set<int>& nodes, unordered_map<int, unordered_set<int>>& next, unordered_map<int,int>& inDegree) {
        queue<int> q;
        for(int node:nodes) {
            if(inDegree[node]==0)
                q.push(node);
        }
        vector<int> ret;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            ret.push_back(cur);
            for(auto nxt:next[cur]) {
                inDegree[nxt]--;
                if(inDegree[nxt] == 0)
                    q.push(nxt);
            }
        }
        if(ret.size() != nodes.size())
            return {};
        return ret;
    }
};