// https://leetcode.com/problems/fizz-buzz

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;

        for(int i=1; i<=n; i++) {
            if (n % 15 == 0) {
                ans.push_back("FizzBuzz");
            } else if (n % 3 == 0) {
                ans.push_back("Fizz");
            } else if ( n % 5 == 0) {
                ans.push_back("Buzz");
            } else {
                ans.push_back(to_string(i));
            }
        }
        return ans;
        
    }
};