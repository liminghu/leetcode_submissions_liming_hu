// https://leetcode.com/problems/restore-ip-addresses

class Solution {
public:
//Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s. 
//You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.
    vector<string> ans = {};
    vector<string> path = {};//if we use global variables, it can run fastest.
    int len = 0;
    vector<string> restoreIpAddresses(string s) {
        len = s.length();
        if(len < 4 || len > 12) //edge cases.
            return ans;
        backtrack(s, 0, 4);  //0: start. 4: residue.

        return ans;
    }

    void  backtrack(string s, int start, int residue) {
        if(start == len && residue == 0) {  //to the end of the string. and we got 4 segments.
            //path to IP addr.
            string ip = path[0]+'.'+path[1]+'.'+path[2]+'.'+path[3];
            ans.push_back(ip);
            return;
        };

        for(int i=start; i<start+3; i++) { //start from the current string pos.and got max 3 chars.
            if( i >= len) //exceed the end of the string.
                break;
            if( residue * 3 < len - i ) //3*3 < residual string length : prune.    
                continue;
            if(isIpSegment(s,start, i)) { //is a valid number?
                string curSeg = s.substr(start, i+1-start);
                path.push_back(curSeg);
                backtrack(s, i+1, residue-1); //got to next char. and segments -1.
                path.pop_back();
            }
        }

    };
    bool isIpSegment(string s,int start, int end) {
        if( end-start+1 > 1 && s[start] == '0' ) //if first char is 0.
            return false;        

        int num = 0;
        for(int i=start; i<=end; i++) {
            num= num*10+s[i]-'0';
        }
        return num>=0 && num<=255;

    }
};