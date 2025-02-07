// https://leetcode.com/problems/design-an-ordered-stream

class OrderedStream {
vector<string> s;
int ptr = 1;
public:
//n (idKey, value) pairs arriving in an arbitrary order, where idKey is an integer between 1 and n and value is a string. No two pairs have the same id.
    OrderedStream(int n) {
        s.resize(n+1, "");
    };
    
    vector<string> insert(int idKey, string value) {
      s[idKey] = value;
      vector<string> res;
      while(ptr<s.size() && !s[ptr].empty())
            res.push_back(s[ptr++]);
      return res;        
    }
};

/**
 * Your OrderedStream object will be instantiated and called as such:
 * OrderedStream* obj = new OrderedStream(n);
 * vector<string> param_1 = obj->insert(idKey,value);
 */