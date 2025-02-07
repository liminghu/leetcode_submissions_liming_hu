// https://leetcode.com/problems/long-pressed-name

class Solution {
public:
    bool isLongPressedName(string name, string typed) { 
        bool ans = false;
        int m= name.length();
        int n = typed.length();
        int i=0, j=0;
        bool different_twice = false;
        while(i<m && j <n) {
            if((name[i] == typed[j]) && (i+1<m) && (j+1<n) && (name[i+1] == typed[j+1])  ) {
                j++; i++;
                different_twice = false;
            } else if(name[i] == typed[j]) {
                j++;
                different_twice = false;
            } else {
                if(different_twice)
                    break;
                i++; 
                different_twice = true;
            };
        }
        
        if(j==n)
            ans = true;
        else
            ans = false;
        
        return ans;
        
    }
};