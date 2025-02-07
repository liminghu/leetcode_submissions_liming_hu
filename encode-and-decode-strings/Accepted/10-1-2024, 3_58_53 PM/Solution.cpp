// https://leetcode.com/problems/encode-and-decode-strings

/*
Design an algorithm to encode a list of strings to a string. The encoded string is then sent 
over the network and is decoded back to the original list of strings.
Machine 1 (sender) has the function:
string encode(vector<string> strs) {
  // ... your code
  return encoded_string;
}
Machine 2 (receiver) has the function:
vector<string> decode(string s) {
  //... your code
  return strs;
}
So Machine 1 does:
string encoded_string = encode(strs);
and Machine 2 does:
vector<string> strs2 = decode(encoded_string);
strs2 in Machine 2 should be the same as strs in Machine 1.
Implement the encode and decode methods.
You are not allowed to solve the problem using any serialize methods (such as eval).
1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] contains any possible characters out of 256 valid ASCII characters.
*/
class Codec {
public:

    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        int n = strs.size();
        cout << "number of strings: " << n << endl;
        string encoded = "";
        for(int i=0; i<n; i++) {
            int len = strs[i].length();
            encoded += to_string(len) + "@";
            encoded += strs[i];
            //cout << "encoded: " << encoded << " after i: " << i << endl;
        };
        //cout << "encoded: " << encoded;
        return encoded;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> decoded;
        int i = 0;
        while( i < s.length() ) {
            int pos = s.find("@", i);  //find @ pos. first.
            int len = stoi( s.substr(i, pos-i) ); //get the number.
            i = pos + 1; //move to the head of the real string.
            decoded.push_back( s.substr(i,len) ); //get the string.
            i += len; //move the head to the next one.
        }
        return decoded;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));