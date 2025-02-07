// https://leetcode.com/problems/sort-characters-by-frequency

class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> m;
        for (char ch : s)
            ++m[ch];
        string ans = "";
        //ans = s;
     
        //sort(counts.begin(), counts.end(), greater<int>());
        auto comp = [](pair<int, char>& a, pair<int, char>& b) { return a.first < b.first; };

        priority_queue < pair<int, char>, vector<pair<int, char>>, decltype(comp)> q(comp);
        for (auto x:m) {
            q.push({ x.second, x.first });
        };
        
        while(!q.empty()) {
             auto t = q.top();
             q.pop();
            
            while(t.first>0) {
                //ans[j] = i;
                ans += t.second;
                t.first--;
                //j++;
            };
        }
        
        //sort(s.begin(), s.end(), [&](char a, char b) { 
        //    return counts[a] > counts[b] || (counts[a] == counts[b] && a < b); 
        //});
        return ans;
    }
};
