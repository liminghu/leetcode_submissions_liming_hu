// https://leetcode.com/problems/largest-number

/*
Given a list of non-negative integers nums, arrange them such that they form the largest number and return it.
Since the result may be very large, so you need to return a string instead of an integer.
*/
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        /*  1 <= nums.length <= 100
            0 <= nums[i] <= 109
        */

        int n = nums.size();
        vector<string> numStr;
        for(int i=0; i<n; i++) {
            numStr.push_back(toString(nums[i]));
        };
 
        sort(numStr.begin(), numStr.end(), [](string&a, string&b){return a+b > b+a;}); //decreasing.
        string ans = "";
        for(int i=0; i<n; i++) {
            ans+= numStr[i];
        };
        return ans;

    }

    string toString(int num) {
        string ans = "";
        if(num == 0)
            return "0";
        while(num>0) {
            int h = num/10;
            int l = num%10;
            ans += '0'+l;
            num = h;
        };
        reverse(ans.begin(), ans.end());
        return ans;
    }
};