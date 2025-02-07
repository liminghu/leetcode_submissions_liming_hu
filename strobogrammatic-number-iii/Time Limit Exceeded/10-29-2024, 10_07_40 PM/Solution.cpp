// https://leetcode.com/problems/strobogrammatic-number-iii

class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        if(low == high) {
            if(isStrobogrammatic(low))
                return 1;
            else
                return 0;
        };
        int lowI = stoi(low);
        int highI = stoi(high);
        if(lowI > highI)
            return 0;
    
        int midI = lowI+(highI-lowI)/2;
        string mid = to_string(midI);
        int ret = 0;
        if(isStrobogrammatic(mid))
            ret++;
        return strobogrammaticInRange(low, to_string(midI-1)) + strobogrammaticInRange(to_string(midI+1), high)+ret;

    }
    bool isStrobogrammatic(string num) {
        string rotated_num;
        for(int i=num.length()-1; i>=0; i--) {
            if(num[i] == '0' || num[i] == '1' || num[i] == '8')
                rotated_num.push_back(num[i]);
            else if(num[i] == '6')
                rotated_num.push_back('9');
            else if(num[i] == '9')
                rotated_num.push_back('6');
            else
                return false;
        }
        return rotated_num == num;
    }
};