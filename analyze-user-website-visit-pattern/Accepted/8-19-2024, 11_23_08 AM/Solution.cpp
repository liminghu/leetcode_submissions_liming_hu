// https://leetcode.com/problems/analyze-user-website-visit-pattern

/*You are given two string arrays username and website and an integer array timestamp. All the given arrays are of the same length and the tuple [username[i], website[i], timestamp[i]] indicates that the user username[i] visited the website website[i] at time timestamp[i].

A pattern is a list of three websites (not necessarily distinct).

For example, ["home", "away", "love"], ["leetcode", "love", "leetcode"], and ["luffy", "luffy", "luffy"] are all patterns.
The score of a pattern is the number of users that visited all the websites in the pattern in the same order they appeared in the pattern.

For example, if the pattern is ["home", "away", "love"], the score is the number of users x such that x visited "home" then visited "away" and visited "love" after that.
Similarly, if the pattern is ["leetcode", "love", "leetcode"], the score is the number of users x such that x visited "leetcode" then visited "love" and visited "leetcode" one more time after that.
Also, if the pattern is ["luffy", "luffy", "luffy"], the score is the number of users x such that x visited "luffy" three different times at different timestamps.
Return the pattern with the largest score. If there is more than one pattern with the same largest score, return the lexicographically smallest such pattern.
*/
class Solution {
public:
    vector<string> mostVisitedPattern(vector<string>& user, vector<int>& t, vector<string>& site) {
        /*  3 <= username.length <= 50
            1 <= username[i].length <= 10
            timestamp.length == username.length
            1 <= timestamp[i] <= 109
            website.length == username.length
            1 <= website[i].length <= 10
            username[i] and website[i] consist of lowercase English letters.
            It is guaranteed that there is at least one user who visited at least three websites.
            All the tuples [username[i], timestamp[i], website[i]] are unique.
        */

            unordered_map<string, map<int, string>> m;
            unordered_map<string, int> cnt;
            int m_cnt = 0;
            string res;
            for (auto i = 0; i < user.size(); ++i) m[user[i]][t[i]] = site[i];
            for (auto u : m) {
                unordered_set<string> ts;
                for (auto it = begin(u.second); it != end(u.second); ++it)
                for (auto it1 = next(it); it1 != end(u.second); ++it1)
                    for (auto it2 = next(it1); it2 != end(u.second); ++it2)
                    ts.insert(it->second + "$" + it1->second + "#" + it2->second);
                for (auto s : ts) ++cnt[s];
            }
            for (auto t : cnt) {
                if (t.second >= m_cnt) {
                res = res == "" || m_cnt < t.second ? t.first : min(res, t.first);
                m_cnt = t.second;
                }
            }
            auto p1 = res.find("$"), p2 = res.find("#");
            return { res.substr(0, p1), res.substr(p1 + 1, p2 - p1 - 1), res.substr(p2 + 1) };
    }
};