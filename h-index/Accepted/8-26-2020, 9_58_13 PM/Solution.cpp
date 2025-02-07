// https://leetcode.com/problems/h-index

class Solution {
public:
    int hIndex(vector<int>& citations) {
        vector<int> count(citations.size()+1, 0);
        for (auto c: citations) {
          if (c>=citations.size()) {
            count[citations.size()]++;
          } else {
            count[c]++;
          }
        }
        
        int sum=0;
        for(int i=count.size()-1; i>=1; i--) {
            sum+=count[i];
            if (sum>=i) {
                return i;
            }
        }
        return 0; 
    }
};