// https://leetcode.com/problems/parallel-courses-ii

/*You are given an integer n, which indicates that there are n courses labeled from 1 to n. You are also given an array relations where 
relations[i] = [prevCoursei, nextCoursei], representing a prerequisite relationship between course prevCoursei and course nextCoursei: 
course prevCoursei has to be taken before course nextCoursei. Also, you are given the integer k.
In one semester, you can take at most k courses as long as you have taken all the prerequisites in the previous semesters for 
the courses you are taking.
Return the minimum number of semesters needed to take all courses. The testcases will be generated such that it is possible to take every course.
*/
class Solution {
public:
    int minNumberOfSemesters(int n, vector<vector<int>>& relations, int k) {
        /*  1 <= n <= 15
            1 <= k <= n
            0 <= relations.length <= n * (n-1) / 2
            relations[i].length == 2
            1 <= prevCoursei, nextCoursei <= n
            prevCoursei != nextCoursei
            All the pairs [prevCoursei, nextCoursei] are unique.
            The given graph is a directed acyclic graph.
            */
        vector<int> dp(1<<n, INT_MAX/2); //min Number Of Semesters taking course 11111111111
        vector<int> prevState(1<<n, 0); //to get into state 111111, what is its preState?
        vector<int> prevCourse(n, 0); //for course i, what is its previous courses?

        for(auto x: relations)
            prevCourse[x[1]-1] |= 1<<(x[0]-1);

        for(int state=0; state<(1<<n); state++) {
            prevState[state] = 0;
            for(int i=0; i<n; i++) {
                if( (state>>i) & 1) {
                    prevState[state] |= prevCourse[i];
                };
            };
        }

        dp[0] = 0;
        for(int state=1; state<(1<<n); state++) {
            for(int subset = state; subset>=0; subset=(subset-1) & state ) {
                if( (__builtin_popcount(state)- __builtin_popcount(subset)<=k )  && (prevState[state] & subset) == prevState[state]) {
                    dp[state] = min(dp[state], dp[subset]+1);
                }
                if(subset==0)
                    break;
            }
        
        }

        return dp[(1<<n)-1];
    }
};