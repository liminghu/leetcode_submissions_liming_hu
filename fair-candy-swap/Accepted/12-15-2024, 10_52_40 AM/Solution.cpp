// https://leetcode.com/problems/fair-candy-swap

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        //Return an integer array answer where answer[0] is the number of candies in the box that Alice must exchange, and answer[1] is the number of candies in the box that Bob must exchange
        int sumAlice = 0;
        int sumBob = 0;
        for(int c:aliceSizes)
            sumAlice += c;
        for(int c:bobSizes)
            sumBob += c;    
        int diff = (sumBob-sumAlice)/2;
        unordered_set<int> setB;
        for(int c:bobSizes)
            setB.insert(c);
        for(int c:aliceSizes) {
            if(setB.find(c+diff)!=setB.end()) {
                return {c, c+diff};
            }
        }
        return {};           
    }
};