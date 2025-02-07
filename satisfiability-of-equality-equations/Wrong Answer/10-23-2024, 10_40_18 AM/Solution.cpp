// https://leetcode.com/problems/satisfiability-of-equality-equations

/*
You are given an array of strings equations that represent relationships between variables where each string equations[i] is of length 4 
and takes one of two different forms: "xi==yi" or "xi!=yi".Here, xi and yi are lowercase letters (not necessarily different) 
that represent one-letter variable names.
Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.

 Example 1:
Input: equations = ["a==b","b!=a"]
Output: false
Explanation: If we assign say, a = 1 and b = 1, then the first equation is satisfied, but not the second.
There is no way to assign the variables to satisfy both equations.

Example 2:
Input: equations = ["b==a","a==b"]
Output: true
Explanation: We could assign a = 1 and b = 1 to satisfy both equations.
 
Constraints:
1 <= equations.length <= 500
equations[i].length == 4
equations[i][0] is a lowercase letter.
equations[i][1] is either '=' or '!'.
equations[i][2] is '='.
equations[i][3] is a lowercase letter.
*/
class Solution {
public:
    class DSU {
        vector<int> father;
    public:
        DSU(int n) {
            father.resize(n);
            for(int i=0; i<n; i++) {
                father[i] = i;
            }

        }
        void Union(int x, int y) {
            int fx = findFather(x);
            int fy = findFather(y);
            if(fx<fy)
                father[y] = fx;
            else
                father[x] = fy;
        }
        int findFather(int x) {
            if( father[x] != x )
                x = findFather(father[x]);
            return father[x];
        }
    };
    bool equationsPossible(vector<string>& equations) { //Return true if it is possible to assign integers to variable names so as to satisfy all the given equations, or false otherwise.
        int n = equations.size();
        unordered_set<char> dict;
        DSU dsu(26);
        for(int i=0; i<n; i++) {
            char a = equations[i][0];
            char re = equations[i][1];   //=, !
            char b = equations[i][3];
            dict.insert(a);
            dict.insert(b);
            if(re == '=')
                dsu.Union(a-'a', b-'a'); 
            else { //!=
                int fb = dsu.findFather(b-'a');
                int fa = dsu.findFather(a-'a');
                if(fa==fb)
                    return false;
            }
        };
        return true;
    }
};