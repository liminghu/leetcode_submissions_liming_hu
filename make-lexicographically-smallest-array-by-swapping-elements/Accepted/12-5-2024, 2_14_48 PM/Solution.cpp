// https://leetcode.com/problems/make-lexicographically-smallest-array-by-swapping-elements

class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<pair<int,int>> sorted;
        for(int i=0; i<n; i++)
            sorted.push_back({nums[i], i});
        sort(sorted.begin(), sorted.end());
        vector<int> rets(n, 0);
        int start = 0;
        for(int end=0; end<n; end++) {
            if(end+1>=n || sorted[end+1].first-sorted[end].first>limit) {
                vector<int> temp(end-start+1, 0);
                for(int i=start; i<=end; i++)
                    temp[i-start] = sorted[i].second;
                sort(temp.begin(), temp.end());
                int j=start;
                for(int i=0; i<temp.size(); i++) {
                    rets[temp[i]] = sorted[j].first;
                    j++;
                }
                start = end+1;
            }
        }
        return rets;
    }
};