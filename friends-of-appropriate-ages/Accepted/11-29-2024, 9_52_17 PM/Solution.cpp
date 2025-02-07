// https://leetcode.com/problems/friends-of-appropriate-ages

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        unordered_map<int, int> count;
        for(auto age: ages)
            count[age]++;
        int res = 0;
        for(auto& x:count) {
            for(auto& y:count) {
                if( request(x.first, y.first))
                    res += x.second* (y.second-(x.first==y.first? 1: 0));  //when they are the same age, a person will not send request to himself.
            }
        }
        return res;
    }
    bool request(int x, int y) {
        return !( y<=0.5*x+7 || y>x || y>100 &&  x<100);
    }
};