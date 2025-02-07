// https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance

/*
There are n cities numbered from 0 to n-1. Given the array edges where edges[i] = [fromi, toi, weighti] represents 
a bidirectional and weighted edge between cities fromi and toi, and given the integer distanceThreshold.
Return the city with the smallest number of cities that are reachable through some path and whose distance is at most 
distanceThreshold, If there are multiple such cities, return the city with the greatest number.
Notice that the distance of a path connecting cities i and j is equal to the sum of the edges' weights along that path.
*/
class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        /*
            2 <= n <= 100
            1 <= edges.length <= n * (n - 1) / 2
            edges[i].length == 3
            0 <= fromi < toi < n
            1 <= weighti, distanceThreshold <= 10^4
            All pairs (fromi, toi) are distinct.
        */
        //floyd
        vector<vector<int>> adjancyCities(n, vector<int>(n, INT_MAX/2)); 
        for(int i=0; i<n; i++) {
            adjancyCities[i][i] = 0;
        }
        for(auto edge: edges) {
            adjancyCities[edge[0]][edge[1]] = min(adjancyCities[edge[0]][edge[1]], edge[2]);
            adjancyCities[edge[1]][edge[0]] = min(adjancyCities[edge[1]][edge[0]], edge[2]);
        };
        for(int k=0; k<n; k++)
            for(int i=0; i<n; i++) 
                for(int j=0; j<n; j++) 
                    adjancyCities[i][j] = min(adjancyCities[i][j], adjancyCities[i][k]+adjancyCities[k][j]);                                

        int res_city = 0;
        int num_reachable = INT_MAX/2;
        for(int i=0; i<adjancyCities.size(); i++) {
            // sort(adjancyCities[i].begin(), adjancyCities[i].end());
            //auto upper  = upper_bound(adjancyCities[i].begin(), adjancyCities[i].end(), distanceThreshold);
            //int num = (upper - adjancyCities[i].begin())/sizeof(int);
            int count = 0;
            for(int j=0; j<adjancyCities[i].size(); j++) {
                if(adjancyCities[i][j] <=distanceThreshold )
                    count++;
            }
            if(count <= num_reachable) {
                res_city = i;
                num_reachable = count;
            };
            cout<< "city i= " << i << " count = " << count << endl; 
        }
        return res_city;
    }
};