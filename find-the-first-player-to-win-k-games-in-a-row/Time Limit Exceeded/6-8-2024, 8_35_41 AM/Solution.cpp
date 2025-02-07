// https://leetcode.com/problems/find-the-first-player-to-win-k-games-in-a-row

class Solution {
public:
    int findWinningPlayer(vector<int>& skills, int k) {  //1 <= skills[i] <= 106, All integers in skills are unique.
        //The first two players in the queue play a game, and the player with the higher skill level wins.
        //After the game, the winner stays at the beginning of the queue, and the loser goes to the end of it.
        //The winner of the competition is the first player who wins k games in a row.
        //Return the initial index of the winning player.

        //competition queue.
        deque<int> cq;
        int n = skills.size();
        for(int i=0; i<n; i++)
            cq.push_back(i);
        
        int n_win_in_row = 0;
        while(n_win_in_row < k) {
            int first = cq.front();
            cq.pop_front();
            int second = cq.front();
            cq.pop_front();

            if(skills[first]>skills[second]) {
                n_win_in_row++;
                cq.push_front(first);
                cq.push_back(second);
            } else {
                n_win_in_row = 1;
                cq.push_front(second);
                cq.push_back(first);                                
            }

        };

        return cq.front();
    }
};