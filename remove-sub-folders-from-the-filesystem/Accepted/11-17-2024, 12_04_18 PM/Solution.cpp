// https://leetcode.com/problems/remove-sub-folders-from-the-filesystem

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        vector<string> res;
        sort(folder.begin(), folder.end());
        string rootFolder = folder[0];
        res.push_back(folder[0]);
        for(int i=1; i<n; i++) {
            string folder_i = folder[i];
            if(compareWith(rootFolder, folder_i)) {
                res.push_back(folder_i);
                rootFolder = folder_i;
            }
        }
        return res;
    }
    bool compareWith(string root, string folder_i) {
        root = root + "/";
        for(int i=0; i<root.size(); i++) {
            if(root[i] != folder_i[i])
                return true;
        }
        return false;
    }
};