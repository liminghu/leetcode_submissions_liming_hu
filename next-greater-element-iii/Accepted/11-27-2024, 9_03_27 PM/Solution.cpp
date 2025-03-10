// https://leetcode.com/problems/next-greater-element-iii

class Solution {
public:
    int nextGreaterElement(int n) {
        vector<int> digits;
        while(n>0) {
            digits.push_back(n%10);
            n = n/10;
        }
        reverse(digits.begin(), digits.end());
        int m = digits.size();
        int i=m-1;
        while(i>=1 && digits[i-1] >= digits[i])
            i--;
        if(i==0)
            return -1;
        i--;
        int j=m-1;
        while(digits[j]<=digits[i])
            j--;
        swap(digits[i], digits[j]);
        sort(digits.begin()+i+1, digits.end());

        long long ret = 0;
        for(int i=0; i<m; i++) {
            ret = ret *10;
            ret += digits[i];
        }
        if(ret >INT_MAX)
            return -1;
        return ret;
    }
};