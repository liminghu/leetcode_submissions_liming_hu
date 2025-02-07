// https://leetcode.com/problems/sqrtx

class Solution {
public:
    int mySqrt(int x) {
        unsigned int l = 1;
		unsigned int r = x+1u;

		while(l<r) {
			unsigned int m = l + (r - l) / 2;
			if (m > x/m) {
				r = m;
			} else {
				l = m + 1;
			};
		}
		return l - 1; //l*l > x.
    }
};