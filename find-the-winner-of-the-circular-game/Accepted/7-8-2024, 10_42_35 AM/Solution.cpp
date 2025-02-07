// https://leetcode.com/problems/find-the-winner-of-the-circular-game

class Solution { //it is a math trick to algorithm.
public:
    int findTheWinner(int n, int k) {  //1 <= k <= n <= 500
        queue<int> q;
        for(int i=1; i<=n; i++) //initialize the queue.
            q.push(i);

        while(  q.size() > 1 ) {
            int count = k-1;
            while ( count > 0 ) {
                int f = q.front();
                q.pop();
                q.push(f);
                count--;
            };
            q.pop(); //delete this loser.
        }

        return q.front(); //only one element left.
    }
};