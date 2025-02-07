// https://leetcode.com/problems/pass-the-pillow

class Solution {
public:
/*
There are n people standing in a line labeled from 1 to n. The first person in the line is holding a pillow initially. Every second, the person holding the pillow passes it to the next person standing in the line. Once the pillow reaches the end of the line, the direction changes, and people continue passing the pillow in the opposite direction.
For example, once the pillow reaches the nth person they pass it to the n - 1th person, then to the n - 2th person and so on.
Given the two positive integers n and time, return the index of the person holding the pillow after time seconds.
*/
    int passThePillow(int n, int time) { //2 <= n <= 1000; 1 <= time <= 1000
        queue<int> q;
        for(int i=1; i<=n; i++) {
            q.push(i);
        }

        int num = 0;
        while(time > 0) {
            num = q.front();
            q.pop();
            q.push(num);
            time--;
        }
        return q.front();
        
    }
};