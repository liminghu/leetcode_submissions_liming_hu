// https://leetcode.com/problems/maximum-average-pass-ratio

struct cmp{
    bool operator()(pair<double,double> a, pair<double,double> b ) {
        double ad = (a.first+1)/(a.second+1)-a.first/a.second;
        double bd = (b.first+1)/(b.second+1)-b.first/b.second;
        return ad < bd;
    }
};
class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        //classes[i] = [passi, totali]. You know beforehand that in the ith class, there are totali total students, but only passi number of students will pass the exam.
        priority_queue<pair<double,double>, vector<pair<double,double>>, cmp> pq;
        for(int i=0; i<classes.size(); i++) {
            pq.push({classes[i][0], classes[i][1]});
        };
        int i=0;
        while(i<extraStudents) {
            pair<double,double> cur = pq.top();
            pq.pop();
            double passi = cur.first+1;
            double totali = cur.second+1;
            pq.push({passi, totali});
            i++;
        }; 
        double avgRatio = 0;
        while(!pq.empty()) {
            pair<double,double> cur = pq.top();
            pq.pop();
            double passratioi = cur.first/cur.second;
            avgRatio += passratioi;
        };
        return avgRatio/classes.size();
    }
};