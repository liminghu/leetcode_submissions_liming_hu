// https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        unordered_map<int, int> remainderCount;
        for(auto num: arr)
            remainderCount[(num%k+k)%k]++;
        for(auto num: arr) {
            int rem_i = (num%k+k)%k;
            if(rem_i == 0) {
                if(remainderCount[rem_i]%2==1)
                    return false;
            } else if(remainderCount[rem_i] != remainderCount[k-rem_i])
                return false;
        }
        return true;
    }
};