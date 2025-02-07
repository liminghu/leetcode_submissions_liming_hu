// https://leetcode.com/problems/design-compressed-string-iterator

class StringIterator {
private:
    int idx = 0;
    string compressedString;
    int count = 0;
    char cur;
public:
    StringIterator(string compressedString) {
        this->compressedString = compressedString;
        this->idx = 0;
        this->count = 0;
        this->cur = NULL;
    }
    
    char next() {
        if(!hasNext())
            return ' ';
        if(count==0) {
            cur = compressedString[idx];
            idx++;
            while(idx<compressedString.length() && isdigit(compressedString[idx]))
                count = count*10+compressedString[idx++]-'0';
        }
        count--;
        return cur;
    }
    
    bool hasNext() {
        return idx<compressedString.length() || count != 0;
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */