// https://leetcode.com/problems/sum-of-digits-of-string-after-convert

class Solution {
public:
    int getLucky(string s, int k) {
        vector<int> transform(s.length(), 0);
        int i=0;
        for(char c: s) {
            transform[i] = c-'a'+1;
            i++;
        }
        int sum = 0;
        for(i=0; i<s.length(); i++) {
            if(transform[i]>=10) {
                sum += transform[i]/10;
                sum += transform[i]%10;
            } else
                sum += transform[i];
        }
        k= k-1;
        while(k>0) {
            int new_sum = 0;
            while(sum>0) {
                new_sum += sum%10;
                sum = sum/10;
            }
            sum = new_sum;
            k--;
        }
        return sum;
    }
};