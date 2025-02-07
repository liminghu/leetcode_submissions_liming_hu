// https://leetcode.com/problems/random-pick-with-weight

class Solution {
private:
    vector<double> weighted_prob;
public:
    Solution(vector<int>& w) {
        long sum = 0;
        for(int i=0; i<w.size(); i++) {
            sum+=w[i];
        };
        
        weighted_prob.push_back(double(w[0])/sum); //suppose: sum!=0
        for(int i=1; i<w.size(); i++) {
            weighted_prob.push_back(weighted_prob[i-1] + double(w[i])/sum);
        };
        
    }
    
    /*
    You are given a 0-indexed array of positive integers w where w[i] describes the weight of the ith index.

You need to implement the function pickIndex(), which randomly picks an index in the range [0, w.length - 1] (inclusive) and returns it. The probability of picking an index i is w[i] / sum(w).

For example, if w = [1, 3], the probability of picking index 0 is 1 / (1 + 3) = 0.25 (i.e., 25%), and the probability of picking index 1 is 3 / (1 + 3) = 0.75 (i.e., 75%).
*/
    
    int pickIndex() {
        int sz = weighted_prob.size();
        
        if(sz == 1)
            return 0;
        
        int rand_num = (double(rand())/RAND_MAX);    //[0, RAND_MAX)
        
        int left = 0;
        int right = sz -1;
        int mid = (left+right)/2;
        
        while(left < right) {                
            if(weighted_prob[mid] < rand_num) {
                left = mid+1;
            } else {
                right = mid;
            }           
        }
        
        return left;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */