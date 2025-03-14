// https://leetcode.com/problems/basic-calculator-ii

/*Given a string s which represents an expression, evaluate this expression and return its value. 
The integer division should truncate toward zero.
You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].
Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
*/
class Solution {
public:
    int calculate(string s) {
        /*
            1 <= s.length <= 3 * 105
            s consists of integers and operators ('+', '-', '*', '/') separated by some number of spaces.
            s represents a valid expression.
            All the integers in the expression are non-negative integers in the range [0, 231 - 1].
            The answer is guaranteed to fit in a 32-bit integer.
        */
        int res = 0;
        vector<int> nums;

        //add "+", remove space.


        int sz = s.length();
        string new_s = "+";
        for(int i=0; i<sz; i++) {
            if(s[i] == ' ')
                continue;
            else {
                new_s += s[i];
            }
        };

        sz = new_s.length();
        //cout << "new_s = " << new_s << endl;
        for(int i=0; i<sz; i++) {
            if(new_s[i] == '+' || new_s[i] == '-') {
                int j=i+1;
                int num = 0;
                while(isdigit(new_s[j])) {
                    num= num*10 + new_s[j]-'0';
                    j++;
                };
                if(new_s[i] == '-')
                    num = -num;
                nums.push_back(num);
                //cout << "num= " << num << endl;
                i=j-1;
            } else if(new_s[i] == '*' || new_s[i] == '/') {
                int j=i+1;
                int num = 0;
                while(isdigit(new_s[j])) {
                    num= num*10 + new_s[j]-'0';
                    j++;
                };
                if(new_s[i] == '*')
                    nums.back() = nums.back()*num;
                else {
                    cout << "num= " << num << endl;
                    nums.back() = nums.back()/num;
                }
                i=j-1;
            }
        }

        for(int i=0; i<nums.size(); i++) {
            res += nums[i];
        }
        return res;


    }
};