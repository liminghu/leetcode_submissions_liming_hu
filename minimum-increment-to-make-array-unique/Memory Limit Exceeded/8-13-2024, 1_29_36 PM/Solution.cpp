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
        map<int, vector<int>> mp; //num, vector of index.

        for(int i=0; i<nums.size(); i++) {
            mp[nums[i]].push_back(i);
        };

        map<int, vector<int>>::iterator it = mp.begin();
        int res = 0;
        while (it != mp.end()) {
            vector<int> idxes = it->second;
            res += idxes.size()-1;
            for (int j=1; j<idxes.size(); j++)
                mp[it->first+1].push_back(idxes[j]);
            ++it;
        };

        return res;
        
    }
};