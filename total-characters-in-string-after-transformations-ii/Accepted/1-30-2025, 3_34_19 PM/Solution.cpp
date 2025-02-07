// https://leetcode.com/problems/total-characters-in-string-after-transformations-ii

class Solution {
    int M = 1e9+7;
public:
    int lengthAfterTransformations(string s, int t, vector<int>& nums) {
        vector<int> freq(26, 0);
        for(char c: s)
            freq[c-'a']++;
        vector<vector<long long>> transform(26, vector<long long>(26, 0));
        for (int i = 0; i < 26; ++i) {
            for (int j = 1; j <= nums[i]; ++j) {
                transform[(i+j)%26][i]++; 
            }
        }
        vector<vector<long long>> powerTransform = matrixExpo(transform, t);
        vector<long long> res(26, 0);
        for(int i=0; i<26; i++) {
            for(int j=0; j<26; j++) {
                res[i] = (res[i] + (powerTransform[i][j] * freq[j])%M) % M;
            };
        };
        long long sum =0;
         for(int i=0; i<26; i++) {
            sum = (sum+res[i])%M;
         };
         return (int)sum;
    }
    vector<vector<long long>> multiply(const vector<vector<long long>>& A, const vector<vector<long long>>& B) {
        vector<vector<long long>> result(26, vector<long long>(26, 0));
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j < 26; ++j) {
                for (int k = 0; k < 26; ++k) {
                    result[i][j] = (result[i][j] + (A[i][k] * B[k][j]) % M ) % M;
                }
            }
        }
        return result;
    }
    vector<vector<long long>> matrixExpo(vector<vector<long long>> base, int t) {
        vector<vector<long long>> result(26, vector<long long>(26, 0));
        for(int i=0; i<26; i++)
            result[i][i] = 1;
        while(t>0) {
            if(t%2 == 1)
                result = multiply(result, base);
            base = multiply(base, base);
            t /= 2;
        }
        return result;
    }
};