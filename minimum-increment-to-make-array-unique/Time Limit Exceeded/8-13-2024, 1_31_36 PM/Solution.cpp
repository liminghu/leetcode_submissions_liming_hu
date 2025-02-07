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
        map<int, int> mp; //num, vector of index.

        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]]++;
        };

        map<int, int>::iterator it = mp.begin();
        int res = 0;
        while (it != mp.end()) {
            int idxes = it->second;
            res += idxes-1;
            for (int j=1; j<idxes; j++)
                mp[it->first+1]++;
            ++it;
        };

        return res;
        
    }
};