// https://leetcode.com/problems/minimum-interval-to-include-each-query

/*
You are given a 2D integer array intervals, where intervals[i] = [lefti, righti] describes the ith interval 
starting at lefti and ending at righti (inclusive). The size of an interval is defined as the number of 
integers it contains, or more formally righti - lefti + 1.
You are also given an integer array queries. The answer to the jth query is the size of the smallest interval
 i such that lefti <= queries[j] <= righti. If no such interval exists, the answer is -1.
Return an array containing the answers to the queries.
1 <= intervals.length <= 105
1 <= queries.length <= 105
intervals[i].length == 2
1 <= lefti <= righti <= 107
1 <= queries[j] <= 107
*/
class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        //intervals[i] = [lefti, righti]  size: righti - lefti + 1.

        //The answer to the jth query is the size of the smallest interval i such that lefti <= queries[j] <= righti. If no such interval exists, the answer is -1.
        vector< pair<int,int> > qs;
        for(int i=0; i<queries.size(); i++)
            qs.push_back( {queries[i], i} );  //we need to have index for the result.
        sort(qs.begin(), qs.end()); //increasing. 
        sort(intervals.begin(), intervals.end()); //increasing left.
        
        int i = 0;
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq; //top min pair: duration, right.
        vector<int> rets(queries.size(), -1);
        for(auto query: qs) {
            auto [time, idx] = query;
            while( i < intervals.size() && intervals[i][0] <= time ) { //this interval is qualified on left: left_i <= q <= q[j]
                pq.push( {intervals[i][1]-intervals[i][0]+1, intervals[i][1]} ); //duration_i, right_i
                i++;
            }

            while(!pq.empty() && pq.top().second < time ) //this interval is not qualified for q: q > right.     the incoming queries will also not choose this interval, since q[j] > q > right. 
                pq.pop();
            if( !pq.empty() )
                rets[idx] = pq.top().first; //duration will be the min.
        } 
        return rets;
    }
};