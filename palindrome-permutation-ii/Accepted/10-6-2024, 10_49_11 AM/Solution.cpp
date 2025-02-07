// https://leetcode.com/problems/palindrome-permutation-ii

/*
Given a string s, return all the palindromic permutations (without duplicates) of it.

You may return the answer in any order. If s has no palindromic permutation, return an empty list.

 

Example 1:

Input: s = "aabb"
Output: ["abba","baab"]
Example 2:

Input: s = "abc"
Output: []
 

Constraints:

1 <= s.length <= 16
s consists of only lowercase English letters.
*/
class Solution {
public:
    vector<string> generatePalindromes(string s) {
        vector<int> dict(26, 0);
        for(char ch: s) 
            dict[ch-'a']++;
        int odd=0;
        char oddC;
        for(int i=0; i<26; i++) {
            if(dict[i] % 2 == 1) {
                odd++;
                oddC = 'a'+i;
            };
        }

        if(odd>1 || odd==1 && s.length()%2==0)
            return {};
        
        string base = "";
        int ll = s.length();
        if(odd==1) {
            base.push_back(oddC);
            dict[oddC-'a']--;
            ll--;
        };

        vector<string> res;
        helper(res, base, dict, ll);
        return res;
    }

    void helper(vector<string>& res, string base, vector<int>& dict, int ll) {
        if(ll == 0) {
            res.push_back(base);
            return;
        }
        for(int i=0; i<26; i++) {
            if(dict[i]==0)
                continue;
            dict[i] -=2;
            string new_base = base;
            new_base.insert(new_base.begin(),'a'+i);
            new_base.push_back('a'+i);
            helper(res, new_base, dict, ll-2);
            dict[i]+=2;
        }
    }
};