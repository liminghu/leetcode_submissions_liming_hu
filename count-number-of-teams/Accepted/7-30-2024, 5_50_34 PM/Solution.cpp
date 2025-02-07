// https://leetcode.com/problems/count-number-of-teams

/*
There are n soldiers standing in a line. Each soldier is assigned a unique rating value.
You have to form a team of 3 soldiers amongst them under the following rules:
    Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
    A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) 
    where (0 <= i < j < k < n).
Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).
*/
class Solution {
public:
    int numTeams(vector<int>& rating) {
        /*
        n == rating.length
        3 <= n <= 1000
        1 <= rating[i] <= 105
        All the integers in rating are unique.
        */

        int sz = rating.size();
        int n_teams = 0;

        //iterate through each soldier as the middle
        for(int mid=0; mid<sz; mid++) {
            int leftSmaller = 0;
            int rightLarger = 0;
            for(int left = mid-1; left>=0; left--) {
                if(rating[left]<rating[mid]) 
                    leftSmaller++;
            };
            for(int right = mid+1; right<sz; right++) {
                if(rating[right]> rating[mid]) 
                    rightLarger++;
            };
            n_teams += leftSmaller*rightLarger;

            int leftLarger = mid - leftSmaller;
            int rightSmaller = sz-mid-1 - rightLarger;
            n_teams += leftLarger*rightSmaller;

        }
        return n_teams;

    }

};