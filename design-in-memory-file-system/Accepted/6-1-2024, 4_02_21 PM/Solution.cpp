// https://leetcode.com/problems/design-in-memory-file-system

class FileSystem {
public:
    struct FileNode {
        bool isfile = false;
        unordered_map<string, FileNode*> next;
        string content = "";
    };
    FileNode *root;

    FileSystem() {
        root = new FileNode();
        
    }

    FileNode* goToPathFolder(string path) { //help function to go to the deepest, and create folder.
        FileNode *cur = root;
        stringstream s(path);
        string folder;
        while(getline(s,folder, '/')) {
            if(folder.size()) {
                if(cur->next[folder] == NULL) //creat new folder.
                    cur->next[folder] = new FileNode();
                cur = cur->next[folder];
            }
        }
        return cur;
    }
    
    vector<string> ls(string path) {
        vector<string> ans;
        FileNode *cur = goToPathFolder(path);
        if(cur->isfile) {
            ans.push_back(path.substr(path.find_last_of('/')+1));
            return ans;
        }
        for(auto&p:cur->next) {
            ans.push_back(p.first);
        };
        sort(ans.begin(), ans.end());
        return ans;
    }
    
    void mkdir(string path) {
        FileNode *cur = goToPathFolder(path);
    }
    
    void addContentToFile(string filePath, string content) {
        FileNode *cur = goToPathFolder(filePath);
        cur->content += content;
        cur->isfile = true;
    }
    
    string readContentFromFile(string filePath) {
        FileNode *cur = goToPathFolder(filePath);
        return cur->content;
        
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * vector<string> param_1 = obj->ls(path);
 * obj->mkdir(path);
 * obj->addContentToFile(filePath,content);
 * string param_4 = obj->readContentFromFile(filePath);
 */