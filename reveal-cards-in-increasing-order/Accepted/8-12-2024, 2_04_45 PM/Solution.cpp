// https://leetcode.com/problems/reveal-cards-in-increasing-order

/*You are given an integer array deck. There is a deck of cards where every card has a unique integer. The integer on the ith card is deck[i].

You can order the deck in any order you want. Initially, all the cards start face down (unrevealed) in one deck.

You will do the following steps repeatedly until all cards are revealed:

Take the top card of the deck, reveal it, and take it out of the deck.
If there are still cards in the deck then put the next top card of the deck at the bottom of the deck.
If there are still unrevealed cards, go back to step 1. Otherwise, stop.
Return an ordering of the deck that would reveal the cards in increasing order.

Note that the first entry in the answer is considered to be the top of the deck.
*/
class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        /*  1 <= deck.length <= 1000
            1 <= deck[i] <= 106
            All the values of deck are unique.
        */
        sort(deck.begin(), deck.end());

        //reverse.

        int sz = deck.size();
        queue<int> deck_q;
        for(int i=0; i<sz; i++)
            deck_q.push(i);

        vector<int> res(sz,0);
        for(int i=0; i<sz; i++) {
            //Take the top card of the deck, reveal it, and take it out of the deck.
            res[deck_q.front()] = deck[i];
            deck[i] = INT_MIN;
            deck_q.pop();
 
            //If there are still cards in the deck then put the next top card of the deck at the bottom of the deck.
            if(!deck_q.empty()) {
                deck_q.push(deck_q.front());
                deck_q.pop();
            };
  
        }

        return res;
    }
};