// https://leetcode.com/problems/expression-add-operators

class Solution {
private:
    vector<string> results;
public:
    vector<string> addOperators(string num, int target) {
        int curPos = 0;
        string preStr = "";
        long preVal = 0;
        long lastVal = 0;
        dfs(num, (long)target, curPos, preStr, preVal, lastVal);
        return results;
    }
    void dfs(string num, long target, int curPos, string preStr, long preVal, long lastVal) {
        if(curPos == num.size()) {
            if(preVal == target) 
                results.push_back(preStr);
            return;
        };
        for(int i=curPos+1; i<=num.size(); i++) {
            string curStr = num.substr(curPos, i-curPos);
            long curVal = stol(curStr);
            if(curStr.size()>1 && curStr[0] == '0')
                break;
            if(curPos == 0) {
                dfs(num, target, i, curStr, curVal, curVal);
            } else {
                dfs(num, target, i, preStr+"+"+curStr, preVal+curVal, curVal);
                dfs(num, target, i, preStr+"-"+curStr, preVal-curVal, -curVal);
                dfs(num, target, i, preStr+"*"+curStr, preVal-lastVal+lastVal*curVal, lastVal*curVal);
            }
        }
    }
};