// https://leetcode.com/problems/longest-absolute-file-path

class Solution {
public:
 int lengthLongestPath(string input) {
			istringstream ss(input);
			string cur;
			int result = 0;
			unordered_map<int, int> pathLen;
			while (getline(ss, cur, '\n')) {
				auto depth = cur.find_last_of("\t");
				string name = (depth == string::npos) ? cur : cur.substr(depth + 1);
				if (cur.find(".") != string::npos) {
					result = max(result, pathLen[depth - 1] + (int)name.size());
				}
				else {
					pathLen[depth] = pathLen[depth - 1] + name.size() + 1;
				}
			}
			return result;
		}
};