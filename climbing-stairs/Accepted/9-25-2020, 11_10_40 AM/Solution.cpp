// https://leetcode.com/problems/climbing-stairs

//DP, fibonaci
class Solution {
public:
  int climbStairs(int n) {
	  // f[i] = climbStairs(i)
	  vector<int> f(n+1, 0);
	  f[0] = 1;
	  f[1] = 1;
	  
	  //f[i] = f[i-1] + f[i-2];
	  for(int i=2; i<=n; i++)
		f[i] = f[i-1] + f[i-2];
		
	  return f[n];
  }
};