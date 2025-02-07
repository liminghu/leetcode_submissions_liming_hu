// https://leetcode.com/problems/number-of-atoms

/*Given a string formula representing a chemical formula, return the count of each atom.
The atomic element always starts with an uppercase character, then zero or more lowercase letters, representing the name.
One or more digits representing that element's count may follow if the count is greater than 1. If the count is 1, no digits will follow.
For example, "H2O" and "H2O2" are possible, but "H1O2" is impossible.
Two formulas are concatenated together to produce another formula.
For example, "H2O2He3Mg4" is also a formula.
A formula placed in parentheses, and a count (optionally added) is also a formula.
For example, "(H2O2)" and "(H2O2)3" are formulas.
Return the count of all elements as a string in the following form: the first name (in sorted order), followed by its count 
(if that count is more than 1), followed by the second name (in sorted order), followed by its count (if that count is more than 1), and so on.

The test cases are generated so that all the values in the output fit in a 32-bit integer. */
class Solution {
public:
    //map<string, int> ans;
    stack<int> st;
    map<string, int> helper(string formula) {
        int sz = formula.length();

        //atom name: Upper, (lower), digits (if more than 1)
        map<string, int> ans;
        int i = 0;
        while( i < sz ) {
           if(isupper(formula[i])) { //start of formula
                string formula_i = "";
                formula_i += formula[i];
                i++;
                while(i<sz && islower(formula[i])) {
                    formula_i += formula[i];
                    i++;
                };
                int count = 0;
                if(i<sz && !isdigit(formula[i]) || i == sz) {
                    if(ans.find(formula_i)==ans.end())
                        ans[formula_i] = 1;
                    else 
                        ans[formula_i] += 1;
                } else {
                    int count = 0;
                    while(i<sz && isdigit(formula[i])) {
                        count = count*10+formula[i]-'0';
                        i++;
                    }
                    if(ans.find(formula_i)==ans.end())
                        ans[formula_i] = count;
                    else 
                        ans[formula_i] += count;
                };                
           } else if( formula[i] =='(' ) { //start of formula which can be repeated.
                st.push(i);
                i++;
           } else if( formula[i] ==')' ) { //end of formula which can be repeated.
                int start = st.top();
                st.pop();
                string new_formula = formula.substr(start+1, i-start-1); //done before.
                map<string, int> ans_sub = helper(new_formula);
                i++;
                int count = 0;
                if(i<sz && !isdigit(formula[i]) || i == sz) {
                    count = 1;
                } else {
                    while(i<sz && isdigit(formula[i])) {
                        count = count*10+formula[i]-'0';
                        i++;
                    }
                };   
                cout << "test";
                for(auto it=ans_sub.begin(); it != ans_sub.end(); it++) {
                    ans[it->first] = ans[it->first] - ans_sub[it->first] + ans_sub[it->first]*count;
                };     
           }

        }
        return ans;
    }

    string countOfAtoms(string formula) {
        /*  1 <= formula.length <= 1000
            formula consists of English letters, digits, '(', and ')'.
            formula is always valid.
        */
        map<string, int> ans_map;
        ans_map = helper(formula);
        string ans = "";
        for(auto i=ans_map.begin(); i != ans_map.end(); i++) {
            if(ans_map[i->first]>1)
                ans += i->first + to_string(ans_map[i->first]);
            else
                ans += i->first;
        }
        return ans;
    }
};