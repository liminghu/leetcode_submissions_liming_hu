// https://leetcode.com/problems/generate-binary-strings-without-adjacent-zeros

class Solution {
public:
    vector<string> validStrings(int n) { //1 <= n <= 18
        //A binary string x is valid if all substrings of x of length 2 contain at least one "1".
        //n =1   ["0","1"]
        //n=2    [01 10 11]
        //n=3     "010", "011", "101", "110", and "111"
        //vector<string> cur_result;
        //backtrack(n, 0);
        vector<string> result;
        vector<string> new_result;
        if(n == 1) {
            result.push_back("0");
            result.push_back("1");
            return result;
        };

        result = validStrings(n-1);
        for(int i=0; i<result.size(); i++) {
            string cur_result_i = result[i];
            if(cur_result_i.size() == 0) {
                new_result.push_back("0");
                new_result.push_back("1");
            } else {
                if(cur_result_i[cur_result_i.length()-1] == '1') {
                    new_result.push_back(cur_result_i+"0");
                    new_result.push_back(cur_result_i+"1");
                } else { //0
                    new_result.push_back(cur_result_i+"1");
                }
            };
        }
        
        return new_result;
        
    }
 
};