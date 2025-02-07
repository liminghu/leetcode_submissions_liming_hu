// https://leetcode.com/problems/fizz-buzz

class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans;

        for(int i=1; i<=n; i++) {
            if (n % 15) {
                ans.push_back("FizzBuzz");
            } else if (n %3) {
                ans.push_back("Fizz");
            } else if ( n%5) {
                ans.push_back("Buzz");
            } else {
                ans.push_back(to_string(i));
            }
        }
        return ans;
        
    }
};