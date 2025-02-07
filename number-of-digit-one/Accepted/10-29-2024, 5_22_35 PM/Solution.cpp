// https://leetcode.com/problems/number-of-digit-one

class Solution {
public:
    int countDigitOne(int n) {
        string s = to_string(n);
        long N = s.size();
        long count = 0;
        for(int i=1; i<=N; i++) {
            long left_count = n / pow(10, i);
            count += left_count * pow(10, i-1);
            if(s[N-i]-'0' > 1)
                count += pow(10,i-1);
            else if(s[N-i]-'0' == 1)
                count += (long)n % (long)pow(10, i-1) + 1;
        }
        return count;
    }
};