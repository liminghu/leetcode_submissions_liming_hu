// https://leetcode.com/problems/high-access-employees

class Solution {
public:
    static bool cmp(vector<string>& a, vector<string>& b ) {
        return (a[0]<b[0]) || (a[0]== b[0] && a[1] <= b[1]);
    }
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        //three or more times within a one-hour period.
        sort(access_times.begin(), access_times.end(), cmp);
        vector<string> res;
        int i=0;
        while(i<access_times.size()) {
            int j=i+1;
            while(j<access_times.size() && access_times[j][0] == access_times[i][0])
                j++;
            j--;
            int count = j-i+1;
            int start = i;
            int end = j;            
            i = j + 1; 
            if(count <3)
                continue;

            while(start <= end-2) {
                bool wh = withinHour(access_times[start][1], access_times[start+2][1]);
                if(wh) {
                    res.push_back(access_times[start][0]);
                    break;
                } else
                    start++;
            }
        }
        return res;
    }
    bool withinHour(string t1, string t2) {
        int time1 = stoi(t1.substr(0,2))*60 + stoi(t1.substr(2,2));
        int time2 = stoi(t2.substr(0,2))*60 + stoi(t2.substr(2,2));

        return time2-time1 < 60;
    }
};