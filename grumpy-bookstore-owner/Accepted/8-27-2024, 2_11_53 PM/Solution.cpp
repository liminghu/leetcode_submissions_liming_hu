// https://leetcode.com/problems/grumpy-bookstore-owner

/*There is a bookstore owner that has a store open for n minutes. You are given an integer array customers of length n where customers[i] 
is the number of the customers that enter the store at the start of the ith minute and all those customers leave after the end of that minute.
During certain minutes, the bookstore owner is grumpy. You are given a binary array grumpy where grumpy[i] is 1 if the bookstore owner is 
grumpy during the ith minute, and is 0 otherwise.
When the bookstore owner is grumpy, the customers entering during that minute are not satisfied. Otherwise, they are satisfied.
The bookstore owner knows a secret technique to remain not grumpy for minutes consecutive minutes, but this technique can only be used once.
Return the maximum number of customers that can be satisfied throughout the day.
*/
class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int sum = 0;
        int n = customers.size();
        for(int i=0; i<n; i++) {
            if(grumpy[i]==0)
                sum += customers[i]; 
        }

        int ret = 0;
        for(int i=0; i<n; i++) {
            if(grumpy[i] == 1)
                sum+= customers[i];
            if(i-minutes>=0 && grumpy[i-minutes]==1)
                sum -= customers[i-minutes];
            ret = max(ret, sum);
        }
        return ret;
    }
};