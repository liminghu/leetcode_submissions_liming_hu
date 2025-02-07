// https://leetcode.com/problems/maximum-population-year

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        const int min_year = 1950;
        const int max_year = 2050;
        int pop[max_year-min_year+1] = {};
        int res=min_year;


        //line sweep.
        for(auto &l: logs) {
            pop[l[0]-min_year]++;  //birth
            pop[l[1]-min_year]--;  //death
        }

        for(auto i=min_year+1; i<max_year; i++) {
            pop[i-min_year] += pop[i-min_year-1];
            res = pop[i-min_year] > pop[res-min_year]? i:res;  
        }

        return res;
    }
};