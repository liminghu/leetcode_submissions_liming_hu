// https://leetcode.com/problems/course-schedule


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
      //DFS + Graph
    graph_ = vector<vector<int>>(numCourses);
    for(const auto& p: prerequisites)
        graph_[p[0]].push_back(p[1]);
        prerequisites;
	  //unknown: 0; visiting: 1 ,visited:2
	  vector<int> v(numCourses, 0);
	  
	  for(int i =0; i<numCourses; i++)
		  if( dfs(i, v) ) return false; // there is cycle.
	  
	  return true;
    }
private:
    vector<vector<int>> graph_;
	bool dfs(int cur, vector<int>& v) {
		if(v[cur] == 1) return true;
		if(v[cur] == 2) return false;
		
		v[cur] = 1; //visiting
		
		for(const int t : graph_[cur])
			if(dfs(t, v)) return true;
		
		v[cur] = 2; //visited
		
		return false;
		
	}
};
