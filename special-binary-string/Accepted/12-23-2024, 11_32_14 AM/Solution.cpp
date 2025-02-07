// https://leetcode.com/problems/special-binary-string

class Solution {
public:
    string makeLargestSpecial(string s) {//s is a special binary string.
        vector<string> vec;
        int n = s.size();
        int i=0;
        while(i<n) {
            int cnt = 0;
            int left = i;
            while(i<n) {
                if(s[i]=='1')
                    cnt++;
                else
                    cnt--;
                i++;
                if(cnt==0) {
                    string temp = s.substr(left+1, (i-1)-(left+1));
                    vec.push_back("1"+ makeLargestSpecial(temp)+"0");
                    break;
                }
            }
        }
        sort(vec.begin(), vec.end(), [](string s1, string s2){return s1+s2>s2+s1;});
        string ret;
        for(auto sub:vec)
            ret+= sub;
        return ret;       
    }
};