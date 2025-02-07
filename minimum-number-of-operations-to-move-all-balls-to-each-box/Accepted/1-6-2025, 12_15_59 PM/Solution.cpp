// https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box

class Solution {
public:
    vector<int> minOperations(string boxes) { //answer[i] is the minimum number of operations needed to move all the balls to the ith box.
        int n = boxes.size();
        vector<int> rets(n, 0);
        int prevOps = 0;
        int sum = boxes[0]-'0';
        for(int i=1; i<n; i++) {
            rets[i] += sum + prevOps;
            prevOps = rets[i];
            sum += boxes[i] -'0';
        }
        prevOps = 0;
        sum = boxes[n-1]-'0';
        for(int i=n-2; i>=0; i--) {
            rets[i] += sum + prevOps;
            prevOps = sum + prevOps;
            sum += boxes[i] -'0';
        }    
        return rets;    
    }
};