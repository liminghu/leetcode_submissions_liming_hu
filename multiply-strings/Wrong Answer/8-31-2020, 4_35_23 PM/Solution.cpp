// https://leetcode.com/problems/multiply-strings

class Solution {
public:
    string multiply(string num1, string num2) {
		int m=num1.length();
        int n=num2.length();
        vector<int> multi(m+n, 0);

		for(int i=m-1; i>=0; i--) {
			for(int j=n-1; j>=0; j--) {
				int multiOne = (num1[i]-'0') * (num2[j]-'0');
				int p1 = i+j;
				int p2 = i+j+1;
				
				int sumOne = multiOne + multi[p2];
				
				multi[p1] +=sumOne/10;
				multi[p2] = sumOne % 10;
			}
		}
		
		string res;
		for(int i=0; i<multi.size(); i++) {
			if(multi[i]==0 && res.length()==0) {
			} else {
			res.push_back('0'+multi[i]);
			};
				
		};
		
		return res;
			
    }
};