// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days

class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        //return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.
        int n = weights.size();
        int left = 1;
        for(int weight:weights)
            left = max(left, weight);

        int right = 500*50000;
        while(left<right) {
            int mid = (left+right)/2;
            bool tf = canLoad(weights, days, mid);
            if(tf)
                right = mid;
            else
                left = mid+1; 
        }
        return left;
    }
    bool canLoad(vector<int>&  weights, int days, int mid) {
        int sum = 0;
        int neededDays = 1;
        for(int weight:weights) {
            sum += weight;
            if(sum > mid) {
                sum = weight;
                neededDays++;
            };
        }
        return neededDays<=days;
    }
};