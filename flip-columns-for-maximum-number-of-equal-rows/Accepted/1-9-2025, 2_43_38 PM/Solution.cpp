// https://leetcode.com/problems/flip-columns-for-maximum-number-of-equal-rows

class Solution {
public:
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        unordered_map<string, int> patternFreq;
        for(auto& currow: matrix) {
            string pattern = "";
            for(int col=0; col<currow.size(); col++) {
                if(currow[0] == currow[col])
                    pattern += "T";
                else
                    pattern += "F";
            }
            patternFreq[pattern]++;
        }
        int maxFreq = 0;
        for(auto& entry: patternFreq) {
            maxFreq = max(entry.second, maxFreq);
        }
        return maxFreq;
    }
};