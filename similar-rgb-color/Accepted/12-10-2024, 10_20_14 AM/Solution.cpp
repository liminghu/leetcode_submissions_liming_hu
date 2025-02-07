// https://leetcode.com/problems/similar-rgb-color

class Solution {
public:
    string similarRGB(string color) {
        string rets = "#";
        for(int i=1; i<6; i+=2)
            rets += findTarget(color.substr(i,2));
        return rets;
    }
    // Given string 'colorSection' representing a two-digit 
    // base 16 number "AB", find out the number "XX" that 
    // has the highest similarity to "AB".
    string findTarget(string colorSection) {
        int num = stoi(colorSection, nullptr, 16);
        int x = round(num*1.0/17); //XX = 16*x +x = 17x
        string ans;
        ans = x>9? 'a'+x-10:'0'+x;
        return ans+ans;
    }
};