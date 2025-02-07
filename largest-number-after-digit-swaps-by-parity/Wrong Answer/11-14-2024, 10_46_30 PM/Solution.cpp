// https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity

class Solution {
public:
    int largestInteger(int num) {
        string s_num = to_string(num); //10 digits.
        for(int i=0; i<s_num.length(); i++) {  //higher digits.
            for(int j=i+1; j<s_num.length(); j++) { //lower digits.
                if( (j-i) % 2 == 0 && s_num[j] > s_num[i] )
                    swap(s_num[j], s_num[i]);
            };
        };
        return stoi(s_num);
    }
};