// https://leetcode.com/problems/assign-cookies

/*
Assume you are an awesome parent and want to give your children some cookies. But, you should give each child at most one cookie.

Each child i has a greed factor g[i], which is the minimum size of a cookie that the child will be content with; and each cookie j 
has a size s[j]. If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content. Your goal is to 
maximize the number of your content children and output the maximum number.
*/
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {   //1 <= g.length <= 3 * 104
                                                                //0 <= s.length <= 3 * 104
                                                                //1 <= g[i], s[j] <= 231 - 1
        int num_children = g.size();
        int num_cookies = s.size();
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0;
        //If s[j] >= g[i], we can assign the cookie j to the child i, and the child i will be content.
        for(int j=0; j<num_cookies; j++) { //g j
            for(int i=0; i<num_children; i++) { //s i
                if( s[j] >= g[i] ) { //child i is content.
                    ans++;
                    g[i] = s[num_cookies-1] + 1; //this children is marked as feeded.
                    s[j] = g[0] - 1; //this cookie is marked as used.
                    break;
                }; 
            }
        }
        return ans;
        
    }
};