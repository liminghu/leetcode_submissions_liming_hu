// https://leetcode.com/problems/average-waiting-time

class Solution {
public:
/*
There is a restaurant with a single chef. You are given an array customers, where customers[i] = [arrivali, timei]:
arrival_i is the arrival time of the ith customer. The arrival times are sorted in non-decreasing order.
time_i is the time needed to prepare the order of the ith customer.
When a customer arrives, he gives the chef his order, and the chef starts preparing it once he is idle. The customer 
waits till the chef finishes preparing his order. The chef does not prepare food for more than one customer at a time. 
The chef prepares food for customers in the order they were given in the input.
Return the average waiting time of all customers. Solutions within 10-5 from the actual answer are considered accepted.
*/
    double averageWaitingTime(vector<vector<int>>& customers) { //1 <= customers.length <= 105
                                                                //1 <= arrivali, timei <= 104
                                                                //arrivali <= arrivali+1
        int sz = customers.size();
        int chefFinishTime = 0;
        double sumWait = 0;
        for(int i=0; i<sz; i++) {
            if ( customers[i][0] >= chefFinishTime ) {
                sumWait += customers[i][1];
                chefFinishTime = customers[i][0]+ customers[i][1];
            } else {
                sumWait += (chefFinishTime-customers[i][0]) + customers[i][1];
                chefFinishTime = chefFinishTime + customers[i][1];               
            }
        };

        return sumWait/sz;
        
    }
};