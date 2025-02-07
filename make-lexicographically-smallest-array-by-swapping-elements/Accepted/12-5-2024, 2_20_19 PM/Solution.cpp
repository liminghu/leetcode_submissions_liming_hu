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
        // "start" and "end" represent the maximum subarray in the sorted "pair" array where
        // the difference between values of consecutive elements is less then "limit"
        for(int end=0; end<n; end++) {
            if(end+1>=n || sorted[end+1].first-sorted[end].first>limit) {
                //"temp" is used to sort the indexes of identified group/subarray  
                vector<int> temp(end-start+1, 0);
                for(int i=start; i<=end; i++)
                    temp[i-start] = sorted[i].second;
                sort(temp.begin(), temp.end());
                //We have identified the group of indexes where, after sorting, difference of consicutive values is <= limit
                //we also already have the sorted form of those indices in the "pair[][]" array
                //copy the sorted values from pair[][] array into result array at their original indexes                
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