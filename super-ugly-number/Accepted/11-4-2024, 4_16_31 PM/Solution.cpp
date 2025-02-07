// https://leetcode.com/problems/super-ugly-number

class Solution {
public:
    int nthSuperUglyNumber(int n, vector<int>& primes) {
        //sort(primes.begin(), primes.end());
        priority_queue<long long, vector<long long>, greater<>> pq; //min pq.
        long long cur = 0;
        int count = 0;
        pq.push(1);
        while(!pq.empty() && count != n) {
            cur = pq.top();
            pq.pop();
            for(int i=0; i<primes.size(); i++) 
                pq.push( cur * primes[i] );
            while(!pq.empty() && cur == pq.top()) //pop duplicates.
                pq.pop();
            count++;
        }
        return cur; 
    }
};