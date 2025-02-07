// https://leetcode.com/problems/find-the-number-of-good-pairs-ii

class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        long long ans = 0;
        vector<int> new_nums1, new_nums2;

        for(int i=0; i<nums1.size(); i++) {
            if (nums1[i]%k == 0)
                new_nums1.push_back(abs(nums1[i]/k));
        }
        sort(new_nums1.begin(), new_nums1.end());
        for(unsigned int i = 0; i < nums2.size(); i++) {
            if(nums2[i] < 0) 
                new_nums2.push_back(-nums2[i]); //make positive.
            else    
                new_nums2.push_back(nums2[i]);
        };

        sort(new_nums2.begin(), new_nums2.end());
        unordered_map<long long, bool> dict;   //<nums_i,nums_j> checked before?  


        for(int i=0; i<new_nums1.size(); i++) {
            if(new_nums1[i] == 0) {
                ans += nums2.size();
                continue;
            }
            
             for(int j=0; j<new_nums2.size(); j++) {
                if(new_nums1[i] < new_nums2[j] || new_nums2[j] == 0)
                    break;
                
                 
                 //int mod_val = new_nums1[i] - new_nums1[i]/new_nums2[j] * new_nums2[j];
                 if(dict.find(new_nums1[i]^new_nums2[j])!=dict.end()) {
                    if( dict[new_nums1[i]^new_nums2[j]] == 1) {
                        ans++;
                        continue;
                    } else {
                        continue;
                    }
                 } 
                 int mod_val= new_nums1[i] - new_nums1[i]/new_nums2[j] * new_nums2[j];
                 if(  mod_val == 0) {
                    ans++;
                    dict[new_nums1[i]^new_nums2[j]] = 1;
                 } else {
                    dict[new_nums1[i]^new_nums2[j]] = 0;
                 }
             }            
        }
        return ans;
        
    }
};