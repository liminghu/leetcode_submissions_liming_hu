// https://leetcode.com/problems/digit-count-in-range

class Solution {
public:
    int digitsCount(int d, int low, int high) {
        if(low>=2)
            return countDigitD(d, high) - countDigitD(d, low-1);
        else
            return countDigitD(d, high);
    }
    int countDigitD(int d, int n) {
        string s = to_string(n);
        int N = s.size();
        long count = 0;
        for(int i=1; i<=N; i++) {
            long left_count = n /pow(10, i);
            count += left_count * pow(10, i-1);
            if(s[N-i]-'0' > d)
                count += pow(10, i-1);
            else if(s[N-i]-'0' == d)
                count += (long)n % (long)pow(10, i-1) +1;
        };
        return count;
    }
};