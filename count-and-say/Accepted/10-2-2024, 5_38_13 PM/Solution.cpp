// https://leetcode.com/problems/count-and-say

class Solution { //https://leetcode.com/problems/count-and-say/solutions/4736427/clean-c-easy-to-understand-soln-simple-recursion-2-pointers/
public:
    string countAndSay(int n) {
        if (n==1) return "1";

        string res_n_1 = countAndSay(n-1);
        string res = "";
        int i=0, j=0;

        //Simple recursion + 2 pointers.
        while ( i < res_n_1.size() ) {
            j= i+1;

            while( j < res_n_1.size() && res_n_1[j] == res_n_1[i])
                    j++;
            string ct_str = to_string(j-i);   //integer to string
            res += ct_str + res_n_1[i];
            i = j;
        }
        return res;
    }
};