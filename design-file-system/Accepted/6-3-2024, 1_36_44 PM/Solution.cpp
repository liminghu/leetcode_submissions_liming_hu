// https://leetcode.com/problems/design-file-system

/*You are asked to design a file system that allows you to create new paths and associate them with different values.
The format of a path is one or more concatenated strings of the form: / followed by one or more lowercase English letters. 
For example, "/leetcode" and "/leetcode/problems" are valid paths while an empty string "" and "/" are not.

Implement the FileSystem class:

bool createPath(string path, int value) Creates a new path and associates a value to it if possible and returns true. 
Returns false if the path already exists or its parent path doesn't exist.
int get(string path) Returns the value associated with path or returns -1 if the path doesn't exist.
*/
class FileSystem {
private:
    unordered_map<string, int> paths;
public:
    FileSystem() {
        paths = unordered_map<string, int>();
        
    }
    
    bool createPath(string path, int value) {
        auto parent = path.substr(0, path.rfind('/')); //rfind: Find last occurrence of content in string
        if(!parent.empty() && !paths.count(parent))
            return false; //Returns false if the path already exists or its parent path doesn't exist.
        if(paths.find(path)!=paths.end())
            return false;
        else {
            paths.emplace(path,value);
            return true;
        }
    }
    
    int get(string path) {
        auto it = paths.find(path);
        if(it==paths.end()) 
            return -1;
        return it->second;
        
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */