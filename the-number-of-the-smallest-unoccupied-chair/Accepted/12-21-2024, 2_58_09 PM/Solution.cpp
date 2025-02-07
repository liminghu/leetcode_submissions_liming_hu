// https://leetcode.com/problems/the-number-of-the-smallest-unoccupied-chair

using PII = pair<int,int>;
class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        //times[i] = [arrivali, leavingi], indicating the arrival and leaving times of the ith friend respectively, 
        //and an integer targetFriend. All arrival times are distinct.
        int n = times.size();
        priority_queue<int,vector<int>, greater<>> empty; //chair id
        priority_queue<PII, vector<PII>, greater<>> occupied; //PII: endtime, person id.
        for(int i=0; i<10000; i++)
            empty.push(i);
        for(int i=0; i<times.size(); i++)
            times[i].push_back(i); //start, end, person id.
        sort(times.begin(), times.end());
        for(auto time: times) {
            int start    = time[0];
            int end      = time[1];
            int personId = time[2];
            while(!occupied.empty() && occupied.top().first <=start) {
                empty.push(occupied.top().second);
                occupied.pop();
            }
            int chair = empty.top();
            empty.pop();
            if(personId ==  targetFriend)
                return chair;
            occupied.push({end, chair});
        }
        return 0;
    }
};