// https://leetcode.com/problems/evaluate-division

class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		//DFS+Graph.
		//g[A][B] = k, A/B = k
		unordered_map<string, unordered_map<string, double>> g;
		for (int i=0; i<equations.size(); i++) {
			const string& A = equations[i][0]; //first
			const string& B = equations[i][1]; //second
			const double k = values[i];
			g[A][B] = k;
			g[B][A] = 1.0 / k;
		};
		
		vector<double> ans;
		for(vector<string> pair: queries) {
			const string& X = pair[0]; //first
			const string& Y = pair[1]; //second	
			if(!g.count(X) || !g.count(Y)) {
				ans.push_back(-1.0);
				continue;
			};
			unordered_set<string> visited;
			ans.push_back(divide(X, Y, g, visited));
		};
		
		return ans;        
    };
private: //get result of X/Y
	double divide(const string& X, const string& Y, unordered_map<string, unordered_map<string, double>>& g, unordered_set<string>& visited) {
		if(X == Y) 
			return 1.0;
		visited.insert(X);
		for(const auto& pair: g[X]) {
			const string& C = pair.first; //first
			if(visited.count(C)) 
				continue;
			double d = divide(C, Y, g, visited); //d=C/Y;
			// X/Y = C/Y * X/C;
            if( d > 0 ) return d*g[X][C];			
		}
		return -1.0;
	}
};