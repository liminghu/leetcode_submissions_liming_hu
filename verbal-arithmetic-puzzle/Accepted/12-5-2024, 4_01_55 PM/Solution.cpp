// https://leetcode.com/problems/verbal-arithmetic-puzzle

class Solution {
    int map[256];
    int visited[10];
public:
    bool isSolvable(vector<string>& words, string result) {
        for(int i=0; i<256; i++)
            map[i] = -1;
        reverse(result.begin(), result.end());
        for(auto& word: words) {
            if(word.size()>result.size())
                return false;
            reverse(word.begin(), word.end());
        }
        return dfs(words, result, 0, 0, 0);
    }
    bool dfs(vector<string>& words, string result, int j, int i, int sum) {
        if( j == result.size() ) {
            if( sum != 0 )
                return false;
            if(result.size()>1 && map[result.back()]==0) //result has leading zero.
                return false;
            return true;
        };
        if( i == words.size() ) { //result row
            if(map[ result[j] ] != -1) {//already mapped.
                if(map[ result[j] ] != sum%10)
                    return false;
                else
                    return dfs(words, result, j+1, 0, sum/10);
            } else {
                if(visited[sum%10] == 1)
                    return false;
                map[result[j]] = sum%10;
                visited[sum%10] = 1;
                if(dfs(words, result, j+1, 0, sum/10))
                    return true;
                map[result[j]] = -1;
                visited[sum%10] = 0;
                return false;
            }
        };

        if( j >= words[i].length() )
            return dfs(words, result, j, i+1, sum);
        char ch = words[i][j];
        if(map[ch]!=-1) {
            if(words[i].size()>1 && j==words.size()-1 && map[ch]==0) //leading zero
                return false;
            return dfs(words, result, j, i+1, sum+map[ch]);
        } else {
            for(int d=0; d<=9; d++) {
                if(visited[d])
                    continue;
                if(d==0 && words[i].size()>1 && j==words[i].size()-1)
                    continue;
                map[ch] = d;
                visited[d] = 1;
                if(dfs(words, result, j, i+1, sum+d))
                    return true;
                map[ch] = -1;
                visited[d] = 0;
            }
            return false;
        }
        return true;
    }
};