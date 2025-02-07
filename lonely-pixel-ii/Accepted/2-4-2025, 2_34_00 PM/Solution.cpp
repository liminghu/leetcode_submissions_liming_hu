// https://leetcode.com/problems/lonely-pixel-ii

class Solution {
public:
    int findBlackPixel(vector<vector<char>>& picture, int target) {
        int m = picture.size();
        if(!m) return 0;
        int n = picture[0].size();
        if(!n) return 0;
        vector<int> rows(m,0), cols(n,0);
        unordered_map<string,int> um;
        vector<string> srows;
        for(int i = 0; i < m; ++i){
            string s; //s is a whole row.
            for(int j = 0; j < n; ++j){
                if(picture[i][j] == 'B'){
                    rows[i]++;
                    cols[j]++;
                }
                s.push_back(picture[i][j]); 
            }
            um[s]++;
            srows.push_back(s); //row strings.
        }
        int res = 0;
        for(int i = 0; i < m; ++i)
            if(rows[i] == target && um[srows[i]] == target)
                for(int j = 0; j < n; ++j)
                     if(picture[i][j] == 'B' && cols[j] == target) 
                        res++;        
        return res;        
    }
};