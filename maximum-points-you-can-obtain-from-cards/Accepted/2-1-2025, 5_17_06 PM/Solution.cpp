// https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
       //In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
        int res = 0;
        for(int i=0; i<k; i++)
            res += cardPoints[i];
        int cur = res;
        int n = cardPoints.size();
        for(int i=k-1; i>=0; i--) {
            cur -= cardPoints[i];
            cur += cardPoints[n-k+i];
            res = max(res, cur);
        }
        return res;
    }
};