// https://leetcode.com/problems/neighboring-bitwise-xor

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        // bitwise XOR (⊕) of adjacent values in a binary array original of length n.
        int n = derived.size();
        vector<int> original(n+1, 0);
        original[0] = 0;
        for(int i=0; i<n; i++) {
            original[i+1] = original[i] ^ derived[i];
        };
        bool checkForZero = (original[0]==original.back());
        original[0] = 1;
        for(int i=0; i<n; i++) {
            original[i+1] = original[i] ^ derived[i];
        };
        bool checkForOne = (original[0]==original.back());
        return   checkForZero |  checkForOne;   
    }
};