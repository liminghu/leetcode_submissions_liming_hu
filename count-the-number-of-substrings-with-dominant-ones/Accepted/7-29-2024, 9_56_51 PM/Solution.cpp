// https://leetcode.com/problems/count-the-number-of-substrings-with-dominant-ones

class Solution {
public:
    int numberOfSubstrings(string s) {
        /*
        You are given a binary string s.
        Return the number of 
        substrings
        with dominant ones.
        A string has dominant ones if the number of ones in the string is greater than or equal to the square of the number of zeros in the string.
        */

        /*1 <= s.length <= 4 * 104
            s consists only of characters '0' and '1'.
        */
       /* int sz = s.length();
        vector<int> numZeros(sz+1, 0);
        vector<int> numOnes(sz+1, 0);
        for(int i=0; i<sz; i++) {
            if(s[i] == '0') {
                numZeros[i+1] =  numZeros[i] + 1;
                numOnes[i+1] = numOnes[i];
            } else {
                numOnes[i+1] =  numOnes[i] + 1;
                numZeros[i+1] = numZeros[i];               
            };
        }

        int start = 0;
        int end = sz -1;

        int ans = 0;
        for(int i=0; i<sz; i++) {
            for(int j=i; j<sz; j++) {
                int numZeroij = numZeros[j+1] - numZeros[i];
                int numOneij = numOnes[j+1] - numOnes[i];
                if( numOneij >= numZeroij * numZeroij )
                    ans++;
            } 
        }
        return ans;*/
        int sz = s.length();
        int cnt = 0;
        
        vector<int> zero_index;
        for (int i = 0; i < sz; i ++)
            if (s[i] == '0') zero_index.push_back(i);
        
        if (zero_index.empty()) return sz*(sz+1)/2;
        int zro_ind = 0;
        
        for (int l = 0; l < sz; l ++) {
            while (zro_ind < zero_index.size() && zero_index[zro_ind] < l) zro_ind ++;
            
            vector<int> valid_zro;
            for (int z = zro_ind; z < zero_index.size() && z < (zro_ind+201); z ++)
                valid_zro.push_back(zero_index[z]);
            valid_zro.push_back(sz);
            
            int zro_cnt = 0;
            int last = l;
            
            for (auto ind : valid_zro) {
                int min_one = zro_cnt*zro_cnt;
                int min_ind = max(l + min_one + zro_cnt - 1, last);

                if (min_ind < ind) cnt += (ind - min_ind); 
                
                last = ind;
                zro_cnt ++;
            }
        }
        return cnt;
    }
};