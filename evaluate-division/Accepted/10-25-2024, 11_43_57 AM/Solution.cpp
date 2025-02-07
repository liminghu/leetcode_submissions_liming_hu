// https://leetcode.com/problems/evaluate-division

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        //equations[i] = [Ai, Bi] and values[i] represent the equation Ai / Bi = values[i]. Each Ai or Bi is a string that represents a single variable.
        int n = equations.size();
        unordered_map<string, unordered_map<string, double>> ValDict;
        for(int i=0; i<n; i++) {
            ValDict[ equations[i][0] ][ equations[i][1] ] = values[i];           
            ValDict[equations[i][1]][equations[i][0]] = 1.0/values[i];      
        }

        vector<double> rets;
        for(auto query:queries) {
            if(ValDict.find(query[0])==ValDict.end() || ValDict.find(query[1])==ValDict.end()) {
                rets.push_back(-1.0);
                continue;
            }
            string val1 = query[0];
            string val2 = query[1];
            unordered_set<string> visited;
            rets.push_back(divide(val1, val2, ValDict, visited));
        }
        return rets;
    }
    double divide(string& X, string& Y, unordered_map<string, unordered_map<string, double>>& ValDict, unordered_set<string>& visited) {
        if(X==Y)
            return 1.0;
        visited.insert(X);
        for(auto& pair: ValDict[X]) {
            string C = pair.first;
            if(visited.count(C))
                continue;
            double d = divide(C, Y, ValDict, visited);    //d = C/Y
            if( d > 0.0 )
                return ValDict[X][C] * d;
        }
        return -1.0;
    }
};