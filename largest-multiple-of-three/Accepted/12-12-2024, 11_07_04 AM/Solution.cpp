// https://leetcode.com/problems/largest-multiple-of-three

class Solution {
public:
    string largestMultipleOfThree(vector<int>& digits) {
        int m1[] = {1,4,7,2,5,8};
        int m2[] = {2,5,8,1,4,7};
        long long sum = 0;
        int count[10] = {};
        for(int i=0; i<digits.size(); i++) {
            count[digits[i]]++;
            sum += digits[i]; 
        };
        while(sum%3 !=0) {
            if(sum%3 == 1) {
                for(auto i: m1) {
                    if(count[i]) {
                        count[i]--;
                        sum-= i;
                        break;
                    }
                }
            } else {
                for(auto i: m2) {
                    if(count[i]) {
                        count[i]--;
                        sum-= i;
                        break;
                    }
                }                
            }
        }
        string res = "";
        for(int i=9; i>=0; i--) 
            res += string(count[i], '0'+i);
        return res.size() && res[0]=='0'? "0": res;
    }
};