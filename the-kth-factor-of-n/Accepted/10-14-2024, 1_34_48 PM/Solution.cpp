// https://leetcode.com/problems/the-kth-factor-of-n

/*
You are given two positive integers n and k. A factor of an integer n is defined as an integer i where n % i == 0.
Consider a list of all factors of n sorted in ascending order, return the kth factor in this list or return -1 if n has less than k factors.

Example 1:
Input: n = 12, k = 3
Output: 3
Explanation: Factors list is [1, 2, 3, 4, 6, 12], the 3rd factor is 3.

Example 2:
Input: n = 7, k = 2
Output: 7
Explanation: Factors list is [1, 7], the 2nd factor is 7.

Example 3:
Input: n = 4, k = 4
Output: -1
Explanation: Factors list is [1, 2, 4], there is only 3 factors. We should return -1.
 
Constraints:
1 <= k <= n <= 1000
 
Follow up:
Could you solve this problem in less than O(n) complexity?
*/
class Solution {
public:
    int kthFactor(int n, int k) { // A factor of an integer n is defined as an integer i where n % i == 0.
        for(int i=1; i<sqrt(n); i++) {
            if (n % i == 0 && --k==0) 
                return i;
        }
        for(int i = sqrt(n); i>=1; i--) {
            if(n % (n/i) == 0 && --k == 0 )
                return n/i;
        }      
        return -1;
 
 /*       int count = 0;
        priority_queue<int, vector<int>> q; 
        for(int i=1; i<=sqrt(n); i++) {
            if (n % i == 0 ) {
                q.push(i);
                count++;
                if(n/i != i)
                    q.push(n/i); 
                if(count == k)
                    return i;
            }
        }
        if(k>q.size())
            return -1;
        while(q.size()>k) {
            q.pop();
        }
        return q.top();*/
    }
};