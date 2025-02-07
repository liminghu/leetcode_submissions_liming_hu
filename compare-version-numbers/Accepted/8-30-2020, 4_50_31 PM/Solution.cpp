// https://leetcode.com/problems/compare-version-numbers

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int s1 = version1.size();
		int s2 = version2.size();
		int i = 0;
		int j = 0;
		
		int d1=0;
		int d2=0;
		while(i<s1 || j<s2) {
			while(i<s1 && version1[i] != '.') {
				d1 = d1 * 10 + version1[i] -'0';
                i++;
			};
			while(j<s2 && version2[j] != '.') {
				d2 = d2 * 10 + version2[j] -'0';
                j++;
			};
			if(d1<d2) return -1;
			if(d1>d2) return 1;
			d1=d2=0;
			i++;
			j++;
		}
		return 0;
    }
};