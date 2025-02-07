// https://leetcode.com/problems/minimum-deletions-to-make-string-balanced

/*
You are given a string s consisting only of characters 'a' and 'b'​​​​.
You can delete any number of characters in s to make s balanced. s is 
balanced if there is no pair of indices (i,j) 
such that i < j and s[i] = 'b' and s[j]= 'a'.
Return the minimum number of deletions needed to make s balanced.
*/
class Solution {
public:
    int minimumDeletions(string s) {
        /*
            1 <= s.length <= 105
            s[i] is 'a' or 'b'​​. 
        */
        int sz = s.length();
        
        vector<int>  num_a_after(sz, 0);  //num of 'a' after i;  num_b_before[sz-1] = 0;
        vector<int>  num_b_before(sz, 0); //num of 'b' before i; num_b_before[0] = 0;
        vector<int> min_del(sz, 0);

        int b_count = 0;
        for(int i=0; i<sz; i++) { //num of 'b' before i
            num_b_before[i] = b_count;
            if(s[i] == 'b') 
                b_count++;
        }

        int a_count = 0;
        for(int i=sz-1; i>=0; i--) { //num of 'a' after i
            num_a_after[i] = a_count;
            if(s[i] == 'a') 
                a_count++;
        }

        int min_deletions = sz;
        for(int i=0; i<sz; i++) { //num_a_after num_b_before
            min_deletions = min(min_deletions, num_a_after[i]+num_b_before[i]);
        };

        return min_deletions;

    }
};