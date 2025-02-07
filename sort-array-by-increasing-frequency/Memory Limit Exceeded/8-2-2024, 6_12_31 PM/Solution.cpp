// https://leetcode.com/problems/sort-array-by-increasing-frequency

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        map<int, int> frequency; //num, frequency
        int sz = nums.size();
        for(int i=0; i<sz; i++) {
            frequency[nums[i]] = frequency[nums[i]]+1;
        }

        vector<pair<int, int> > rets = sort_map(frequency);
        vector<int> res;
        for(int i=0; i<rets.size(); i++) {
            for(int j=0; i<rets[i].second; j++) {
                res.push_back(rets[i].first);
            }
        };

        return res;

    }

private:
    bool cmp(pair<int, int>& first, pair<int, int>& second) { //num, frequency
        return first.second < second.second || first.second == second.second && first.first > second.first;
    }

    vector<pair<int, int> > sort_map(map<int, int>& frequency) {
        // Declare vector of pairs 
        vector<pair<int, int> > A; 
 
        // Copy key-value pair from Map 
        // to vector of pairs 
        for (auto& it : frequency) { 
            A.push_back(it); 
        } 
 
        // Sort using comparator function 
        sort(A.begin(), A.end(), [](pair<int, int>& first, pair<int, int>& second) {return first.second < second.second || first.second == second.second && first.first > second.first;}); 

        return A;
        // Print the sorted value 
        //for (auto& it : A) { 
        //    cout << it.first << ' '
        //        << it.second << endl; 
        //} 
    }
    
};