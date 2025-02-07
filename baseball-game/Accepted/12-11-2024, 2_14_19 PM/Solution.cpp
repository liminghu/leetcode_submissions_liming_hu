// https://leetcode.com/problems/baseball-game

class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> st;
        for(auto& op: operations) {
            if(op[0] == '+') {
                st.push_back(st[st.size()-1]+st[st.size()-2]);
            } else if(op[0] == 'D') {
                st.push_back(st[st.size()-1]*2);
            } else if(op[0] == 'C') {
                st.pop_back();
            } else {
                st.push_back(stoi(op));
            }
        };
        int sum =0;
        for(int i=0; i<st.size(); i++)
            sum+= st[i];
        return sum;
    }
};