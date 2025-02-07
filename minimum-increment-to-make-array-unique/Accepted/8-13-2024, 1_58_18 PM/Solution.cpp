// https://leetcode.com/problems/minimum-increment-to-make-array-unique

/*You are given an integer array nums. In one move, you can pick an index i 
where 0 <= i < nums.length and increment nums[i] by 1.
Return the minimum number of moves to make every value in nums unique.
The test cases are generated so that the answer fits in a 32-bit integer.
*/
class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        /*  1 <= nums.length <= 105
            0 <= nums[i] <= 105
        */
       int n = nums.size();
       int max_val = 0;
       int minIncrements = 0;

       for(int val: nums) {
        max_val = max(max_val, val);
       };

       /*The minimum length of frequencyCount would be the largest value in nums, and it 
       must be long enough to hold the new values we get from incrementing any duplicates. 
       Keep in mind that the maximum number of duplicates that we could possibly have is 
       equal to the length of nums.*/
       vector<int> count(n+max_val, 0);
       //vector<int> count(max_val+1, 0);
       for(int val: nums)
        count[val]++;
       
       for(int i=0; i<count.size(); i++) {
            if(count[i] <=1)
                continue;
            minIncrements += count[i] - 1;
            count[i+1] += count[i] - 1;
            //count[i] = 1;
       }
       return minIncrements;
       
       /* map<int, int> mp; //num, count.

       // sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;
        };

        map<int, int>::iterator it = mp.begin();
        long res = 0;
        while (it != mp.end()) {
            if(it->second > 1) {
                res += it->second - 1;
                mp[it->first + 1 ] += it->second-1;
            }
            ++it;
        };

        return res;*/
        
    }
};