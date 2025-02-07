// https://leetcode.com/problems/convert-a-number-to-hexadecimal

class Solution {
public:
    vector<char> map = {'0', '1','2', '3','4','5','6','7','8','9','a','b','c','d','e','f'};
    string toHex(int num) {
        if(num == 0)
            return "0";
        string result;
        unsigned int u_num = num;
        while(u_num!=0) {
            result = map[ u_num & 15 ] + result;
            u_num = u_num >> 4; 
        }
        return result;
    }
};