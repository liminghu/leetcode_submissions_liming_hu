// https://leetcode.com/problems/boats-to-save-people

/*You are given an array people where people[i] is the weight of the ith person, and an infinite 
number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two 
people at the same time, provided the sum of the weight of those people is at most limit.

Return the minimum number of boats to carry every given person.
*/
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        /*
            1 <= people.length <= 5 * 104
            1 <= people[i] <= limit <= 3 * 104
        */
        //people[i] is the weight of the ith person
        //Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.
        sort(people.begin(), people.end());
        int i=0;
        int j=people.size()-1;
        if ( i==j )
            return 1;
        int res = 0;
        while(i<j) {
            if(people[i] + people[j] <=limit) {
                res++;
                i++;
                j--;
            }else {
                j--;
                res++;
            };
        }
        if(i==j)
            res++;
        return res;
    }
};