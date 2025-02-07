// https://leetcode.com/problems/minimum-cost-to-hire-k-workers

/*
There are n workers. You are given two integer arrays quality and wage where quality[i] is the quality of the 
ith worker and wage[i] is the minimum wage expectation for the ith worker.

We want to hire exactly k workers to form a paid group. To hire a group of k workers, we must pay them according 
to the following rules:

Every worker in the paid group must be paid at least their minimum wage expectation.
In the group, each worker's pay must be directly proportional to their quality. This means if a worker’s quality is 
double that of another worker in the group, then they must be paid twice as much as the other worker.
Given the integer k, return the least amount of money needed to form a paid group satisfying the above conditions. 
Answers within 10-5 of the actual answer will be accepted.
*/
class Solution {
public:
    static bool cmp(pair<int,int>&a, pair<int,int>&b) {
        return a.second*1.0/a.first < b.second*1.0/b.first;
    }
    
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        /*  n == quality.length == wage.length
            1 <= k <= n <= 104
            1 <= quality[i], wage[i] <= 104
        */
        vector<pair<int,int>> persons;
        for(int i=0; i<quality.size();i++) {
            persons.push_back({quality[i], wage[i]});
        }

        sort(persons.begin(), persons.end(), cmp);

        priority_queue<int> pq_quality; //max
        int sum_quality = 0;
        double ret = 1e30;

        for(int i=0; i<persons.size(); i++) { //unit page is increasing.
            sum_quality += persons[i].first;
            pq_quality.push(persons[i].first);
            if(pq_quality.size() > k) {
                sum_quality -= pq_quality.top();
                pq_quality.pop();
            }

            if(pq_quality.size() == k) {
                double unitWage = persons[i].second * 1.0/persons[i].first;
                ret = min(ret, unitWage*sum_quality);
            }
        }
        return ret;
    }
};