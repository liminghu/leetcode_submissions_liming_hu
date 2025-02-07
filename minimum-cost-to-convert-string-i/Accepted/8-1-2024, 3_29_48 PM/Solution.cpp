// https://leetcode.com/problems/minimum-cost-to-convert-string-i

/*
You are given two 0-indexed strings source and target, both of length n and consisting of lowercase English letters. 
You are also given two 0-indexed character arrays original and changed, and an integer array cost, where cost[i] 
represents the cost of changing the character original[i] to the character changed[i].

You start with the string source. In one operation, you can pick a character x from the string and change it to the 
character y at a cost of z if there exists any index j such that cost[j] == z, original[j] == x, and changed[j] == y.

Return the minimum cost to convert the string source to the string target using any number of operations. If it is 
impossible to convert source to target, return -1.

Note that there may exist indices i, j such that original[j] == original[i] and changed[j] == changed[i].
*/
using LL = long long;
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        /*  1 <= source.length == target.length <= 105
            source, target consist of lowercase English letters.
            1 <= cost.length == original.length == changed.length <= 2000
            original[i], changed[i] are lowercase English letters.
            1 <= cost[i] <= 106
            original[i] != changed[i]
        */

        LL d[26][26];
        for(int i=0; i<26; i++) {
            for(int j=0; j<26; j++) {
                if(i==j)
                    d[i][j] = 0;
                else
                    d[i][j] = LLONG_MAX/2;
            }
        }

        for(int i=0; i<cost.size(); i++) {
            char sor = original[i];
            char des = changed[i];
            d[sor-'a'][des-'a'] = min(d[sor-'a'][des-'a'], (LL)cost[i]);
        }

        //Floyd algorithm: brute force.
        for(int k=0; k<26; k++) 
             for(int i=0; i<26; i++) 
                for(int j=0; j<26; j++) 
                    d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
        LL ret = 0;
        for(int i=0; i<source.length(); i++) {
            char sor = source[i];
            char des = target[i];
            //min cost from sor to des.
            if(d[sor-'a'][des-'a'] == LLONG_MAX/2)
                return -1;
            ret += d[sor-'a'][des-'a'];
        }

        return ret;           

        //pair<int, int>: changed char, cost.
       /* vector<vector<pair<int, int>>> adjacencyList(26); //26 single sources.
        int sz = original.size();
        for(int i=0; i<sz; i++) {
            char sor = original[i];
            char des = changed[i];
            adjacencyList[sor-'a'].push_back( { des-'a', cost[i] } );
        };

        //calculate shortest paths for all possible char conversions.
        vector<vector<long long>> minConversionCosts(26, vector<long long>(26,0));
        for(int i=0; i<26; i++) {
            minConversionCosts[i] = dijkstra(i, adjacencyList);
        } 

        int n = source.length();

        long long min_cost = 0;
        for(int i=0; i<n; i++) {
            char sor = source[i];
            char des = target[i];
            //min cost from sor to des.
            if(sor != des) {
                long long cur_cost = minConversionCosts[sor-'a'][des-'a'];
                if( cur_cost == -1 ) //no path.
                    return -1;
                min_cost += cur_cost;
            }
        }

        return min_cost;*/
    }
/*
private:
    //find min conversion costs from startChar to all other.
    vector<long long> dijkstra(int startChar, vector<vector<pair<int, int>>>& adjacencyList) {
        priority_queue< pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> min_pq; //cost, char
        min_pq.push({0, startChar});
        vector<long long> minCosts(26, -1);
        while( !min_pq.empty() ) {
            auto [curCost, curChar] = min_pq.top();
            min_pq.pop();
            if(minCosts[curChar] != -1 && minCosts[curChar] < curCost)  //no need to update.
                continue;
            for( auto& [targetChar, conversionCost]: adjacencyList[curChar] ) {
                long long newTotalCost = curCost + conversionCost;
                if(minCosts[targetChar] == -1 || newTotalCost < minCosts[targetChar]) {
                    minCosts[targetChar] = newTotalCost;
                    min_pq.push({newTotalCost, targetChar});
                }
            }
        }

        return minCosts;
    }*/
};