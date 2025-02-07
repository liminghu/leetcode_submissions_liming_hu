// https://leetcode.com/problems/removing-stars-from-a-string

class Solution {
public:
    string removeStars(string s) {  //stack
        string ans;
        stack<int> s_star; //stack of star location.
        int i=0;
        int n=s.length();
        if(n==0)
            return s;

        while(i<n) { 
            if (s[i]!='*') {
                ans.push_back(s[i]);
            } else { ////find the first star
                int current_star = 0;
                s_star.push(i);
                while(!s_star.empty()) {
                    current_star = s_star.top();
                    s_star.pop();
                    if(ans.length()>0)
                        ans.pop_back();
                };
            }
            i++;
        }; 

        return ans;
        
    }
};