// https://leetcode.com/problems/zigzag-iterator

class ZigzagIterator {
private:
    vector<int> v1;
    vector<int> v2;
    int p1;
    int p2;
    bool first;
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        this->v1 = v1;
        this->v2 = v2;
        p1 = 0;
        p2 = 0;
        if(v1.size()>0)
            first = true;
        else
            first = false;
    }

    int next() {
        if(first) {
            first = false;
            if(p1<v1.size()) {
                int ret = v1[p1];
                p1++;
                return ret;
            } else {
                if(p2<v2.size()) {
                    int ret = v2[p2];
                    p2++;
                    return ret;
                }
            }
        } else {
            first = true;
           if(p2<v2.size()) {
                int ret = v2[p2];
                p2++;
                return ret;
            } else {
                if(p1<v1.size()) {
                    int ret = v1[p1];
                    p1++;
                    return ret;
                }
            }            
        }
        return -1;
    }

    bool hasNext() {
        if(p1<v1.size() || p2<v2.size())
            return true;      
        else
            return false;  
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */