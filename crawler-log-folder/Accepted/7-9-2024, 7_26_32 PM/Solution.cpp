// https://leetcode.com/problems/crawler-log-folder

/*
The Leetcode file system keeps a log each time some user performs a change folder operation.

The operations are described below:

"../" : Move to the parent folder of the current folder. (If you are already in the main folder, remain in the same folder).
"./" : Remain in the same folder.
"x/" : Move to the child folder named x (This folder is guaranteed to always exist).
You are given a list of strings logs where logs[i] is the operation performed by the user at the ith step.

The file system starts in the main folder, then the operations in logs are performed.

Return the minimum number of operations needed to go back to the main folder after the change folder operations.
*/
class Solution {
public:
    int minOperations(vector<string>& logs) {
        /*
        1 <= logs.length <= 103
        2 <= logs[i].length <= 10
        logs[i] contains lowercase English letters, digits, '.', and '/'.
        logs[i] follows the format described in the statement.
        Folder names consist of lowercase English letters and digits.
        */

        int sz = logs.size();
        stack<string> dirs;

        for(int i=0; i<sz; i++) {
            string logs_i = logs[i];
            char first = logs_i[0];
            char second = logs_i[1];

            if(first == '.' && second == '.') {
                if(!dirs.empty())
                    dirs.pop();
            } else if(first == '.' && second == '/') {
                continue;
            } else {
                dirs.push(logs_i);
            }
        }
        
        return dirs.size();
    }
};