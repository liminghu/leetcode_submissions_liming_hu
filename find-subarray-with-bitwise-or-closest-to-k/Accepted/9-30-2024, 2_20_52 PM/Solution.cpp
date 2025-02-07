// https://leetcode.com/problems/find-subarray-with-bitwise-or-closest-to-k

/*You are given an array nums and an integer k. You need to find a subarray of nums such that the
 absolute difference between k and the bitwise OR of the subarray elements is as small as possible. 
 In other words, select a subarray nums[l..r] such that |k - (nums[l] OR nums[l + 1] ... OR nums[r])| 
 is minimum.

Return the minimum possible value of the absolute difference.
A subarray is a contiguous non-empty sequence of elements within an array.
1 <= nums.length <= 105
1 <= nums[i] <= 109
1 <= k <= 109
*/
class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) { //1 <= nums[i] <= 109 ; 1 <= k <= 109
        int res = INT_MAX;
        //for bitwise OR, result can not decrease.
        // j, i two pointers, nums[j..i].
        // j = i = 0;
        //add nums[i] into total val (OR of nums[j..i])
        //update j if val > k,  then the val will decrease..
        //update i if val < k, then the val will increase.
        //for any update, we calculate: diff = abs(val-k);
        //return the min_diff.
        vector<int> p(32, 0); //represent how many 1s on each bits.
        for(int i=0, j=0; i<nums.size(); i++) {
            update(p, nums[i]);
            res = min( res, abs( k - get(p) ) );
            if(res == 0)
                return 0;
            while(j<i && get(p) > k ) {
                //subtract nums[j] from p.
                for(int t=0; t<32; t++) {
                    if(nums[j]>>t & 1)
                        p[t]--;
                }
                int diff = abs(get(p)-k);
                if(diff==0)
                    return 0;
                res = min(res, diff);
                j++;
            }
        }
        return res;
    }
    int get(vector<int>& p) {
        int res = 0;
        for(int t=0; t<32; t++) {
            if(p[t]>0)
                res |= (1<<t);
        }
        return res;
    }

    void update(vector<int>& p, int num) {
        for(int t=0; t<32; t++) {
            if(num>>t & 1)
                p[t]++;
        }
    }    
};