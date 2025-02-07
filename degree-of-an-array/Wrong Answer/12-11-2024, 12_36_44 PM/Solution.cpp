// https://leetcode.com/problems/degree-of-an-array

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, pair<pair<int,int>,int>> count;
        int maxFreq = 0;
        int left = 0;
        int right = 0;
        for(int i=0; i<nums.size(); i++) {
            if(count.find(nums[i])==count.end()) {
                count[nums[i]].first.first = i;
                count[nums[i]].first.second = i;
                count[nums[i]].second = 1;
            } else {
                count[nums[i]].first.second = i;
                count[nums[i]].second++;
            }
        };

        maxFreq = 0;
        int ret = 0;
        for(auto& item: count) {
            pair<pair<int,int>,int> itemProp = item.second;
            if( itemProp.second > maxFreq) {
                maxFreq = itemProp.second;
                ret = itemProp.first.second - itemProp.first.first+1;
                //cout << maxFreq << endl;
            }
        }
        return ret;
    }
};