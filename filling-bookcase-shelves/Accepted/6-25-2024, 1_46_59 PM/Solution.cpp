// https://leetcode.com/problems/filling-bookcase-shelves

class Solution {
public:
/*
You are given an array books where books[i] = [thicknessi, heighti] indicates the thickness and height of the ith book. You are also given an integer shelfWidth.

We want to place these books in order onto bookcase shelves that have a total width shelfWidth.

We choose some of the books to place on this shelf such that the sum of their thickness is less than or equal to shelfWidth, then build another level of the shelf 
of the bookcase so that the total height of the bookcase has increased by the maximum height of the books we just put down. We repeat this process until there are 
no more books to place.

Note that at each step of the above process, the order of the books we place is the same order as the given sequence of books.

For example, if we have an ordered list of 5 books, we might place the first and second book onto the first shelf, the third book on the second shelf, and the 
fourth and fifth book on the last shelf.
Return the minimum possible height that the total bookshelf can be after placing shelves in this manner.
*/
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) { //1 <= books.length <= 1000
                                                                       //1 <= thicknessi <= shelfWidth <= 1000
                                                                       //1 <= heighti <= 1000
        //dp[i] => 将数组S[1:i]分成若干个subarray，最小化“每个subarray的最大值之和”，保存该值
        int sz = books.size();
        vector<int> dp(sz+1, 0);
        dp[0] = 0; //height
        for(int i=0; i<sz; i++) { 
            dp[i+1] = dp[i] + books[i][1]; //on the new layer.
            int totalWidth = 0;
            int maxHeight = 0;
            for(int j=i; j>=0; j--) {      
                totalWidth += books[j][0];       
                if(totalWidth <=shelfWidth) {
                    maxHeight = max(maxHeight, books[j][1]);  
                    dp[i+1] = min(dp[i+1], dp[j]+maxHeight);
                } else
                    break;
            }
        }
        return dp[sz];
    }
};