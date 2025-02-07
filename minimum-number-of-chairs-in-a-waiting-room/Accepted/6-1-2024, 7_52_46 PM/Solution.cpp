// https://leetcode.com/problems/minimum-number-of-chairs-in-a-waiting-room

class Solution {
public:
    int minimumChairs(string s) {   //maximum number of people waiting in the room.
        int n = s.length();
        int ans = 0;
        int max_people = 0;
        int cur_people = 0;
        for(char c:s) {
            if (c == 'E')
                cur_people++;
            else
                cur_people--;
            if(cur_people > max_people)
                max_people = cur_people;

        }
        return max_people;
        
    }
};