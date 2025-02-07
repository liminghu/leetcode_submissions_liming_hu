// https://leetcode.com/problems/encode-and-decode-tinyurl

/*TinyURL is a URL shortening service where you enter a URL such as https://leetcode.com/problems/design-tinyurl and it returns a short URL 
such as http://tinyurl.com/4e9iAk. Design a class to encode a URL and decode a tiny URL.

There is no restriction on how your encode/decode algorithm should work. You just need to ensure that a URL can be encoded to a tiny URL 
and the tiny URL can be decoded to the original URL.

Implement the Solution class:

Solution() Initializes the object of the system.
String encode(String longUrl) Returns a tiny URL for the given longUrl.
String decode(String shortUrl) Returns the original long URL for the given shortUrl. It is guaranteed that the given shortUrl was 
encoded by the same object.
*/
class Solution {
public:
    string chars = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    unordered_map<string, string> mp;
    long long counter;

    Solution() {
        mp.clear();
        counter = 1;
    }
    string getString() {
        int c = counter;
        string res = "";
        while(c>0) {
            res += chars[c % 62 ];
            c /= 62;
        };
        return res;
    }
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        counter = counter +1;
        string shortUrl = getString(); //to_string(counter);
        mp[shortUrl] = longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return mp[shortUrl];
        
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));