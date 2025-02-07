// https://leetcode.com/problems/reformat-date

class Solution {
public:
    string reformatDate(string date) {  //date = "20th Oct 2052"
        unordered_map<string, string> months = {{"Jan", "01"}, {"Feb", "02"}, {"Mar", "03"}, {"Apr", "04"}, {"May", "05"}, 
                                                {"Jun", "06"}, {"Jul", "07"}, {"Aug", "08"}, {"Sep", "09"}, {"Oct", "10"}, 
                                                {"Nov", "11"}, {"Dec", "12"}
                                                };
        stringstream ss(date);
        string d, m, y;
        ss>>d; ss>>m; ss>>y; //d m y

        //reformat d: 20th
        //d = 
        unordered_map<string, string> days = {{"1st", "01"}, {"2nd", "02"}, {"3rd", "03"}, {"4th", "04"}, {"5th", "05"}, 
                                                {"6th", "06"}, {"7th", "07"}, {"8th", "08"}, {"9th", "09"}, {"10th", "10"}, 
                                                {"11th", "11"}, {"12th", "12"}, {"13th", "13"}, {"14th", "14"}, {"15th", "15"},
                                                {"16th", "16"}, {"17th", "17"}, {"18th", "18"}, {"19th", "19"}, {"20th", "20"},
                                                {"21st", "21"}, {"22nd", "22"}, {"23rd", "23"}, {"24th", "24"}, {"25th", "25"},
                                                {"26th", "26"}, {"27th", "27"}, {"28th", "28"}, {"29th", "29"}, {"30th", "30"},
                                                {"31st", "31"}
                                                };
        string format_d = days[d];
        string format_m = months[m];   // Oct  10


        string ans; //"2052-10-20"
        ans = y + "-" + format_m + "-" + format_d;

        return ans;
    }
};