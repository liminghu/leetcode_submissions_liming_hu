// https://leetcode.com/problems/design-a-text-editor

class TextEditor {
string before, after;
public:
    TextEditor() {//Initializes the object with empty text.
        
    }
    
    void addText(string text) {//Appends text to where the cursor is. The cursor ends to the right of text.
        before.insert(end(before), begin(text), end(text));
    }
    
    int deleteText(int k) { //Deletes k characters to the left of the cursor. Returns the number of characters actually deleted.
        k = min(k, (int)before.size());
        before.resize(before.size()-k);
        return k;
    }
    
    string cursorLeft(int k) {//Moves the cursor to the left k times. Returns the last min(10, len) characters to the left of the cursor, where len is the number of characters to the left of the cursor.
        while(k-- && !before.empty()) {
            after.push_back(before.back());
            before.pop_back();
        }
        return before.substr(before.size()-min( (int)before.size(), 10 ) );
    }
    
    string cursorRight(int k) {//Moves the cursor to the right k times. Returns the last min(10, len) characters to the left of the cursor, where len is the number of characters to the left of the cursor.
        while(k-- && !after.empty()) {
            before.push_back(after.back());
            after.pop_back();
        }
        return before.substr(before.size()-min( (int)before.size(), 10 ) );        
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */