// https://leetcode.com/problems/find-the-celebrity

/* The knows API is defined for you.
      bool knows(int a, int b); */

class Solution {
public:
    int findCelebrity(int n) {
        int candidate = 0; //only one candidate.
        for(int i=1; i<n; i++) {
            if(knows(candidate, i))
                candidate = i;
        }
        for(int i=0; i<n; i++) { //verify the candidate.
            if(i==candidate)
                continue;
            if(knows(candidate, i) || !knows(i, candidate))
                return -1;
        }
        return candidate;
    }
};