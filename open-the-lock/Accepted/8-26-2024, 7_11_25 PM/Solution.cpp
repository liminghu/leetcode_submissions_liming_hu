// https://leetcode.com/problems/open-the-lock

/*You have a lock in front of you with 4 circular wheels. Each wheel has 10 slots: 
'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'. The wheels can rotate freely and wrap 
around: for example we can turn '9' to be '0', or '0' to be '9'. Each move consists of 
turning one wheel one slot.
The lock initially starts at '0000', a string representing the state of the 4 wheels.
You are given a list of deadends dead ends, meaning if the lock displays any of these 
codes, the wheels of the lock will stop turning and you will be unable to open it.
Given a target representing the value of the wheels that will unlock the lock, return 
the minimum total number of turns required to open the lock, or -1 if it is impossible.
*/
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        /*  1 <= deadends.length <= 500
            deadends[i].length == 4
            target.length == 4
            target will not be in the list deadends.
            target and deadends[i] consist of digits only.
        */
        unordered_set<string> deads(deadends.begin(), deadends.end());
        unordered_set<string> visited;
        queue<string> q;

        if(deads.find("0000") !=deads.end() )
            return -1;
        q.push("0000");
        visited.insert("0000");
        if(target == "0000")
            return 0;
        int step = -1;
        while(!q.empty()) {
            step++;
            int len = q.size();
            while(len >0) {
                len--;
                string state = q.front();
                q.pop();
                for(string& next:scroll(state)) {
                    if(visited.find(next)!=visited.end())
                        continue;
                    if(deads.find(next)!=deads.end())
                        continue;
                    if(next == target)
                        return step+1;
                    q.push(next);
                    visited.insert(next);
                }
            }
        }

        return -1;
    }
    vector<string> scroll(string state) {
        vector<string> rets;
        for(int i=0; i<4; i++) {
            for(int d=-1; d<=1; d+=2) {
                int num = state[i]-'0';
                num = (num+d+10)%10;
                string temp = state;
                temp[i] = '0'+num;
                rets.push_back(temp);
            }
        }
        return rets;
    }
};