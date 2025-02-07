// https://leetcode.com/problems/course-schedule-ii


class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
       vector<vector<int>> graph(numCourses);
       for(const auto& p:  prerequisites) {
            graph[p[1]].push_back(p[0]);
       } 
       //states: 0: unknown, 1:visiting, 2: visted
       vector<int> v(numCourses,0);
       vector<int> ans;
       
       for(int i=0; i<numCourses; i++) {
            if( dfs(i, graph,v,ans) ) return {};
       }    
        std:reverse(ans.begin(), ans.end());
        return ans;
    }
       
private:
    bool dfs(int cur, vector<vector<int>>& graph, vector<int>& v, vector<int>& ans) {
        if(v[cur] == 1) return true; //there is a loop.
        if(v[cur] == 2) return false; //visited, do not need to do anything.
        
        v[cur] = 1; //visiting
        
        for(const int t: graph[cur]) //[ai, bi] this means you must take the course bi before the course ai.
            if(dfs(t, graph,v,ans)) return true;
        
        v[cur] = 2; //visited
        ans.push_back(cur);
        
        return false; 
    }
};