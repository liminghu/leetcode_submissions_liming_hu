// https://leetcode.com/problems/odd-string-difference

class Solution {
public:
    string oddString(vector<string>& words) {
        int n = words[0].length();
        //difference[i][j] = words[i][j+1] - words[i][j] where 0 <= j <= n - 2. 
        //Note that the difference between two letters is the difference between their 
        //positions in the alphabet i.e. the position of 'a' is 0, 'b' is 1, and 'z' is 25.
        vector<int> difference1(n-1, 0);
        int count1=0;
        string first = "";
        vector<int> difference2(n-1, 0);
        int count2 = 0;
        string second = "";
        for(auto word: words) {
            vector<int> difference(n-1, 0);
            for(int i=0; i<n-1; i++) {
                difference[i] = word[i+1]-word[i]; 
            };
            if(count1==0 ) {
                count1 = 1;
                difference1 = difference;
                first = word;
            } else if(difference != difference1 && count2==0) {
                count2 = 1;
                difference2 = difference;
                second = word;
            } else {
                if(difference == difference1) 
                    count1++;
                else if (difference == difference2)
                    count2++;
                if(count1>1 && count2==1)
                    return second;
                if(count2>1 && count1==1)
                    return first; 
            }
        }
        if(count1==1)
            return first;
        else
            return second;
    }
};