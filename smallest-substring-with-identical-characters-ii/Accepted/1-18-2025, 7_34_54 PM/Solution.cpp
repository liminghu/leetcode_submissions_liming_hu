// https://leetcode.com/problems/smallest-substring-with-identical-characters-ii

class Solution {
public:
    int minLength(string s, int numOps) { //s consists only of '0' and '1'.
        int n = s.length();
        vector<int> identical;
        int i=0;
        while(i<n) {
            int j = i;
            while(j<n && s[j]==s[i])
                j++;
            identical.push_back(j-i);
            i=j;
        }
        int left = 1, right = n;
        while(left<right) {
            int mid = left+(right-left)/2;
            if(checkOk(s, identical, numOps, mid))
                right = mid;
            else
                left = mid+1;
        }
        return left;
    }
    bool checkOk(string& s, vector<int>& identical, int numOps, int len) {
        if(len ==1) {
            int count = 0;
            for(int i=0; i<s.length(); i++)
                count += (s[i]-'0')==(i%2);
            if(count<=numOps)
                return true;
            count = 0;
            for(int i=0; i<s.length(); i++)
                count += (s[i]-'0')!=(i%2);
            if(count<=numOps)
                return true;    
            return false;
        };
        int count = 0;
        for(int i=0; i<identical.size(); i++) {
            int x = identical[i];
            count += ceil( (x-len)*1.0/(len+1));
            if(count>numOps)
                return false;
        }
        return true;
    }
};