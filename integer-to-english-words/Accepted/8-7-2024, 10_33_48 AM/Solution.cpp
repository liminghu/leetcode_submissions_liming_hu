// https://leetcode.com/problems/integer-to-english-words

//Convert a non-negative integer num to its English words representation.
class Solution {
public:
    string numberToWords(int num) {
        //0 <= num <= 231 - 1 = 2,147,483,647
        // 647
        // 483 thousand
        // 147 million
        //2 billion
        string res = "";
        int billion = num / 1000000000;
        if (billion > 0 )
            res += helper(billion) + " " + "Billion";

        num = num - billion * 1000000000;
        int million = num / 1000000;
        if (million > 0 ) {
            if(res.length() != 0)
                res += " ";
            res += helper(million) + " " + "Million";
        }

        num = num - million * 1000000;
        int thousand = num /1000;
        if (thousand > 0 ) {
            if(res.length() != 0)
                res += " ";
            res +=  helper(thousand) + " " + "Thousand";
        }
        num = num - thousand * 1000;
        int less_thousand = num;

        if(res.length() != 0 && num == 0 )
            return res;
        if(less_thousand > 0 && res.length() != 0)
            res += " ";
        res += helper(less_thousand);
        
        return res;
    }

    //0=<num < 1000
    string helper(int num) {
        int hundred = num /100;
        num = num - hundred * 100;
        int ten = num /10;
        num = num - ten * 10;
        //0~19;
        vector<string> dict = {"Zero", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
        //20~90
        vector<string> tens_dict = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};

        string res = "";
        if(hundred > 0 ) {
            if(res.length() != 0)
                res += " ";
            res += dict[hundred];
            res += " ";
            res += "Hundred";
        };

        if(ten >= 2 ) {
            if(res.length() != 0)
                res += " ";
            res +=  tens_dict[ten-2];
        };
        if( ten < 2 && ten > 0) {
            if(res.length() != 0)
                res += " ";
            res +=  dict[num+ ten*10];
        } else {
            if(num == 0 && res.length() != 0)
                return res;
            if(res.length() != 0)
                res += " ";
            res += dict[num];
        }
        return res;
    }
};