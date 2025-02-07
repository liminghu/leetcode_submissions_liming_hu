// https://leetcode.com/problems/number-of-senior-citizens

/*You are given a 0-indexed array of strings details. Each element of details provides 
information about a given passenger compressed into a string of length 15. The system is such that:

The first ten characters consist of the phone number of passengers.   10 phone
The next character denotes the gender of the person.  11 gender
The following two characters are used to indicate the age of the person. 12~13 age
The last two characters determine the seat allotted to that person.  14~15 seat.
Return the number of passengers who are strictly more than 60 years old.
 */
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int sz = details.size();
        int res = 0;
        for(int i=0; i<sz; i++) {
            char age1 = details[i][11];
            char age2 = details[i][12];
            if(age1>'6' || age1== '6' && age2 != '0')
                res++;
        }

        return res;
        
    }
};