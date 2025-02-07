// https://leetcode.com/problems/fibonacci-number

class Solution {
public:
   int fib(int N) {
    	int f_n_1 = 1;
 		int f_n_2 = 0;
		int f_n = f_n_1 + f_n_2;
		if( N == 0 ) return 0;
		if( N == 1 ) return 1;
		for(auto i=2; i<=N; i++) {
			f_n = f_n_1 + f_n_2;
			f_n_2 = f_n_1;
			f_n_1 = f_n;
		};
		return f_n;				
    }
};