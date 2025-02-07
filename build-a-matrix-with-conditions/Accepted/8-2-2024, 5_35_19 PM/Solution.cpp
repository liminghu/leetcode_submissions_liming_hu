// https://leetcode.com/problems/build-a-matrix-with-conditions

/*
You are given a positive integer k. You are also given:

a 2D integer array rowConditions of size n where rowConditions[i] = [abovei, belowi], and
a 2D integer array colConditions of size m where colConditions[i] = [lefti, righti].
The two arrays contain integers from 1 to k.

You have to build a k x k matrix that contains each of the numbers from 1 to k exactly once. The remaining cells should have the value 0.

The matrix should also satisfy the following conditions:

The number abovei should appear in a row that is strictly above the row at which the number belowi appears for all i from 0 to n - 1.
The number lefti should appear in a column that is strictly left of the column at which the number righti appears for all i from 0 to m - 1.
Return any matrix that satisfies the conditions. If no answer exists, return an empty matrix.

 */
class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        /*  2 <= k <= 400
            1 <= rowConditions.length, colConditions.length <= 104
            rowConditions[i].length == colConditions[i].length == 2
            1 <= abovei, belowi, lefti, righti <= k
            abovei != belowi
            lefti != righti
        */
        //topology sort.
        vector<int> row = topo(k, rowConditions);
        vector<int> col = topo(k, colConditions);

        if(row.empty() || col.empty() )
            return {};
        vector<pair<int,int>> pos(k+1, {0,0}); //p[v]: (x,y)
        for(int i=0; i<k; i++) {
            pos[row[i]].first = i;
        }
        for(int j=0; j<k; j++) {
            pos[col[j]].second = j;
        }

        vector<vector<int>> matrix(k, vector<int>(k,0));
        for(int v=1; v<=k; v++) {
            matrix[pos[v].first][pos[v].second] = v;
        }

        return matrix;

    }

    vector<int> topo(int k, vector<vector<int>>& conditions) {
        vector<vector<int>> next(k+1,vector<int>()); //next[i]: adjancent nodes for ith node.
        vector<int> inDegree(k+1,0); //ith node in degree.

        for(auto& x: conditions) {
            next[x[0]].push_back(x[1]);
            inDegree[x[1]]++;
        }

        queue<int> q;
        for(int v=1; v<=k; v++) {
            if(inDegree[v] == 0) 
                q.push(v);
        }

        vector<int> res;
        while(!q.empty()) {
            int cur = q.front();
            q.pop();
            res.push_back(cur);

            for(int x:next[cur]) {
                inDegree[x]--;
                if(inDegree[x] == 0)
                    q.push(x);
            }
        }

        if(res.size()!=k) //check loop.
            return {};
        return res;

    };
};