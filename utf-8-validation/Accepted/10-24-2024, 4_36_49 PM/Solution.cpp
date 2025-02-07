// https://leetcode.com/problems/utf-8-validation

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int numberofBytes = 0;
        int mask1 = 1 << 7; //mask to check the most significant bit.
        int mask2 = 1 << 6; //mask to check the most 2 significant bits.

        for(int i=0; i<data.size(); i++) {
            if(numberofBytes == 0) { //we're starting
                int mask = 1 << 7;
                while( (mask & data[i]) != 0) {//1
                    numberofBytes++;
                    mask = mask >> 1;
                };

                if(numberofBytes == 0) { //one byte utf8
                    continue;
                }
                if(numberofBytes > 4 || numberofBytes == 1)
                    return false;

            } else {
                // data[i] should have most significant bit set and
                // second most significant bit unset. So, we use the two masks
                // to make sure this is the case.
                if( !( ( data[i] & mask1 ) != 0 && ( mask2 & data[i] ) == 0 ) ) {
                    return false;
                }                
            }
            numberofBytes--; // We reduce the number of bytes to process by 1 after each integer.
        }
        return numberofBytes == 0;
    }
};