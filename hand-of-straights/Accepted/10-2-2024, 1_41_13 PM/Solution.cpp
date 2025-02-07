// https://leetcode.com/problems/hand-of-straights

/*
Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size 
groupSize, and consists of groupSize consecutive cards.
Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, 
return true if she can rearrange the cards, or false otherwise.
Constraints:

1 <= hand.length <= 104
0 <= hand[i] <= 109
1 <= groupSize <= hand.length
*/
class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if( n==0 )
            return true;
        
        if(n % groupSize != 0)
            false;
        
        unordered_map<int, int> count_mp;
        for(auto card: hand) 
            count_mp[card]++;
        
        sort(hand.begin(), hand.end()); //increasing.
        for(int i=0; i<n; i++) {
            if( count_mp[ hand[i] ] == 0 ) //this card has been used, skip.
                    continue;
            for(int j=0; j<groupSize; j++) { //we must have consecutive groupSize numbers starting from hand[i], if this card is not used before.
                int currCard = hand[i] + j;
                if(count_mp[currCard] == 0 )
                    return false;
                count_mp[currCard]--;
            }
        }
        return true;
    }
};