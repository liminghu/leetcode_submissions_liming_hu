// https://leetcode.com/problems/text-justification

/*Given an array of strings words and a width maxWidth, format the text such that each line has exactly 
maxWidth characters and is fully (left and right) justified.
You should pack your words in a greedy approach; that is, pack as many words as you can in each line. 
Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.
Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a 
line does not divide evenly between words, the empty slots on the left will be assigned more spaces 
than the slots on the right.
For the last line of text, it should be left-justified, and no extra space is inserted between words.
Note:

A word is defined as a character sequence consisting of non-space characters only.
Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
The input array words contains at least one word.
*/
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        /*  1 <= words.length <= 300
            1 <= words[i].length <= 20
            words[i] consists of only English letters and symbols.
            1 <= maxWidth <= 100
            words[i].length <= maxWidth
        */
        vector<string> rets;
        for(int i=0; i<words.size(); i++) {  //suppose the current row: [words[i]...... words[j]]
            int j = i; //the words in current row (adding the rows before)
            int count = 0; //the filled letters per row.
            while( j < words.size() && count <= maxWidth ) {
                if(count == 0)
                    count += words[j].size();
                else 
                    count += 1 + words[j].size();
                j++; //open interval.
            }
            j--; // close interval.
            if( count > maxWidth ) {
                count -= 1 + words[j].size();
                j--;
            }

            if( j == words.size()-1 ) { //last word.
                string temp;
                for(int k=i; k<=j; k++) {
                    temp += words[k] + " ";
                }
                temp.pop_back(); //pop the last space.
                temp += addspace(maxWidth-temp.size());
                rets.push_back(temp);
            } else {
                rets.push_back(printline(words, maxWidth, i, j));
            }
            i = j;
        }
        return rets;
    }
    string printline(vector<string>& words, int maxWidth, int i, int j) {
        if( i == j ) {
            return words[i] + addspace(maxWidth - words[i].size());
        };

        int total = 0;
        for(int k=i; k<=j; k++)
            total += words[k].size();
        int space = (maxWidth-total) / (j-i);
        int extra = (maxWidth-total) - space * (j-i);

        string ret;
        for(int k=i; k < i+extra; k++) {
            ret += words[k] + addspace(space+1);
        };
        for(int k=i+extra; k<j; k++) {
            ret += words[k] + addspace(space);
        }

        ret += words[j];
        
        return ret;
    }
    string addspace(int k) {
        string ret;
        for(int i=0; i<k; i++) 
            ret+= " ";
        return ret;
    }
};