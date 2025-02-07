// https://leetcode.com/problems/string-to-integer-atoi

class Solution {
public:
    int myAtoi(string str) {
		long long res = 0;
		int start = 0;
		bool pos = true;
		if(str.length() == 0) 
            return 0;
		while(str[start] == ' ') {
			start++;
		};
		if(str[start] == '+') {
			pos = true;
			start++;
		} else if(str[start] == '-') {
			pos = false;
			start++;
		} else if(!(str[start] >= '0' && str[start] <= '9')) {
			return 0;
		};
		
		while (start < str.length()) {
			if (str[start] >= '0' && str[start] <= '9') {
				res = res * 10 + str[start]-'0';
				start++;
			} else 
				break;
		};
			
        if (pos) {
            if (res >INT_MAX) 
                return INT_MAX;
            else 
                return int(res);
        } else {
            res = 0 - res;
            if (res <INT_MIN) 
                return INT_MIN;
            else 
                return int(res);            
        }
        
    }
};