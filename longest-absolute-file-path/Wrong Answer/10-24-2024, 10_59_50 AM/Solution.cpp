// https://leetcode.com/problems/longest-absolute-file-path

class Solution {
public:
    int lengthLongestPath(string input) {
        int cur_length = 0;
        int max_length = 0;
        dfs(input, cur_length, max_length);
        return max_length;
    }
    int dfs(string input, int& cur_length, int& max_length) {
        int pos = input.find("\n\t");
        if (pos==std::string::npos) {
            if(isValidFile(input)) {
                if(input.length()+ cur_length >max_length)                    
                    max_length = input.length()+ cur_length;
                return max_length;
            } else
                return max_length;
        }
        int dir_length = pos+1;
        while(input[pos]=='\t' || input[pos]=='\n')
            pos++;
        input = input.substr(pos);
        cur_length = cur_length + dir_length;
        return dfs(input, cur_length, max_length);
        
    }
    bool isValidFile(string input) {
        int pos = input.find(".");
        if (pos==std::string::npos) 
            return false;
        else
            return true;
    }
};