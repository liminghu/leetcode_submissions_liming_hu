// https://leetcode.com/problems/basic-calculator

class Solution {
public:
  int calculate(string s) {    
    function<int(int&)> eval = [&](int& pos) {
      int ret = 0;
      int sign = 1;
      int val = 0;
      while (pos < s.size()) {
        const char ch = s[pos];
        if (isdigit(ch)) {
          val = val * 10 + (s[pos++] - '0');
        } else if (ch == '+' || ch == '-') {
          ret += sign * val;
          val = 0;
          sign = ch == '+' ? 1 : -1;
          ++pos;
        } else if (ch == '(') {
          val = eval(++pos);
        } else if (ch == ')') {          
          ++pos;
          break;
        } else {
          ++pos;
        }
      }
      return ret += sign * val;
    };
    int pos = 0;
    return eval(pos);
  }
};