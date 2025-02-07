// https://leetcode.com/problems/maximum-xor-of-two-numbers-in-an-array

//Given an integer array nums, return the maximum result of nums[i] XOR nums[j], where 0 <= i <= j < n.
class Solution {
    class TrieNode {
        public:
            TrieNode* children[2]; //0, 1
    };

public:
    int findMaximumXOR(vector<int>& nums) {
        //1 <= nums.length <= 2 * 105
        //0 <= nums[i] <= 231 - 1
        TrieNode* root = new TrieNode();
        for(auto num:nums) {
            TrieNode* node = root;
            for(int k=31; k>=0; k--) {
                if(node->children[(num>>k)&1] == NULL)
                    node->children[(num>>k)&1] = new TrieNode();;
                node = node->children[(num>>k)&1];
            }
        }

        int ret = 0;
         for(auto num:nums) {
            TrieNode* node = root;
            int ans = 0;
            for(int k=31; k>=0; k--) {
                if(node->children[1-(num>>k)&1] != NULL) {
                    ans = ans*2 + 1;
                    node = node->children[1-(num>>k)&1];

                } else {
                    ans = ans*2;
                    node = node->children[(num>>k)&1];
                }
            }
            ret = max(ret, ans);
        }
        return ret;

    }
};