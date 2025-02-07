// https://leetcode.com/problems/remove-sub-folders-from-the-filesystem

class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        int n = folder.size();
        vector<string> res;
        vector<bool> removed(n, false);
        sort(folder.begin(), folder.end());
        for(int i=0; i<n-1; i++) {
            string folder_i = folder[i] + "/";
            if(removed[i])
                continue;
            for(int j=i+1; j<n; j++) {
                if(removed[j])
                    continue;
                string folder_j = folder[j];
                int found_pos = folder_j.find(folder_i);
                if( folder_i != folder_j &&  found_pos != string::npos) 
                        removed[j] = true;
            }
        }
        for(int i=0; i<n; i++) { 
            if(!removed[i])
                res.push_back(folder[i]);
        }
        return res;
    }
};