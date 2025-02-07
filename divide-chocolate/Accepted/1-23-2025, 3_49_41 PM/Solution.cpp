// https://leetcode.com/problems/divide-chocolate

class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int k) {
        int numPeople = k+1;
        int l = *min_element(sweetness.begin(), sweetness.end());
        int r = accumulate(sweetness.begin(), sweetness.end(), 0)/numPeople;
        while(l<r) {
            int mid = (l+r+1)/2;
            int curSweet = 0, peopleWithCho = 0;
            for(int a: sweetness) {
                curSweet += a;
                if( curSweet >= mid) {
                    peopleWithCho++;
                    curSweet = 0;
                }
            }
            if(peopleWithCho >= numPeople) 
                l = mid;
            else
                r = mid -1;
        }
        return l;
    }
};