// https://leetcode.com/problems/the-earliest-moment-when-everyone-become-friends

class Solution {
vector<int> parent;
int findParent(int x) {
    return parent[x] == x? parent[x]: findParent(parent[x]);
}
public:
    int earliestAcq(vector<vector<int>>& logs, int n) { //2 <= n <= 100
        //logs[i] = [timestampi, xi, yi] indicates that xi and yi will be friends at the time timestampi.
        sort(logs.begin(), logs.end());
        parent.resize(n, 0);
        for(int i=0; i<n; i++)
            parent[i] = i;
        for(int i=0; i<logs.size(); i++) {
            int x = findParent(logs[i][1]);
            int y = findParent(logs[i][2]);
            if( x != y ) {
                n--;
                if( n == 1 )
                    return logs[i][0];
                if(x<y)
                    parent[y] = x;
                else
                    parent[x] = y;
            }
        }
        return -1;
    }
};