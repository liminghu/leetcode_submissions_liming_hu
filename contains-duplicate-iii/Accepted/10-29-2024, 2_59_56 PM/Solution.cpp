// https://leetcode.com/problems/contains-duplicate-iii

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
        /*Find a pair of indices (i, j) such that:
            i != j,
            abs(i - j) <= indexDiff.
            abs(nums[i] - nums[j]) <= valueDiff, and
            Return true if such pair exists or false otherwise.
        */
        int n = nums.size();
        set<int> set; //increasing...  BST
        for(int i=0; i<nums.size(); i++) {
            auto s = set.lower_bound(nums[i]); //Returns an iterator pointing to the first element in the range [first,last) which does not compare less than nums[i] floor...
            if (s != set.end() && *s <= nums[i] + valueDiff ) //*s >= nums[i]
                return true;
            if( s != set.begin() )  {
                auto g = prev(s);
                if(nums[i] <= *g + valueDiff)
                    return true;
            }
            set.insert(nums[i]);
            if(set.size()>indexDiff) {
                set.erase(nums[i-indexDiff]);
            }
        }
        return false;
    }
};