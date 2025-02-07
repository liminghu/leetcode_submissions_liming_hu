// https://leetcode.com/problems/merge-intervals

/*对于区间合并的题目，一般都会采用和252类似的“扫描线”算法。对于每一个区间[a,b]，我们在a时刻记录+1，在b时刻记录-1. 然后我们再在时间轴上顺次遍历每一个时间点，
统计这些+1和-1的总和。我们会发现当sum从0变为正数时，意味着一个merged interval的开始；当sum从正数变成0时，意味着一个merged interval的结束。
这样就巧妙地把所有存在overlap的区间都合并到了一起。

需要注意的是，对于相同的时刻，如果同时存在多个+1或者-1，应该先处理+1后处理-１。比如[a,b]和[b,c]两个区间，在处理b时刻时，按照先+1再-1的顺序，
就不会出现sum=0的情况了，也就避免了merged interval在b处断开。
*/
class Solution {
public:
   static bool cmp(vector<int> a, vector<int> b) {
        if(a[0] == b[0])
            return a[1] > b[1];
        else
            return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
     vector<vector<int>> diff;
     for(auto& interval:intervals) {
        diff.push_back({interval[0], 1});
         diff.push_back({interval[1], -1});
     };
     sort(diff.begin(), diff.end(), cmp);
     vector<vector<int>> result;
     int start=0, end=0;
     int sum = 0;
     for(int i=0; i<diff.size(); i++) {
        if(sum==0 && diff[i][1] == 1) {
            start = diff[i][0];
        }else if(sum ==1  && diff[i][1] == -1) {
            end = diff[i][0];
            result.push_back({start,end});
        }
        sum += diff[i][1];
     };
     return result;

     /*   sort(intervals.begin(), intervals.end());
        vector<vector<int>> merged;
        for(auto interval: intervals) {
            if(merged.empty() || merged.back()[1] < interval[0])
                merged.push_back(interval);
            else {
                merged.back()[1] = max(merged.back()[1], interval[1]);
            }
        }
        return merged;*/
        
    }
};