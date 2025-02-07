// https://leetcode.com/problems/unique-email-addresses

class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
       unordered_set<string> st;
       for(string& email: emails) {
            string shortEmail;
            for(char c: email) {
                if(c=='+' || c=='@')
                    break;
                if(c=='.')
                    continue;
                shortEmail+=c;
            }
            shortEmail += email.substr(email.find('@'));
            st.insert(shortEmail);
       }
       return st.size();

    }
};