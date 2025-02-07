// https://leetcode.com/problems/longest-absolute-file-path

class Solution {
public:
    int lengthLongestPath(string input) {
        istringstream ss(input);
		string cur;
		int result = 0;
		size_t max_len = 0;
		//Main idea is using hashmap to store the path length for each depth. The depth is the number of "\t".
		//For each filename, calculate the path length by the current depth.
		unordered_map<int, int> path_len; 
		path_len[0] = 0;
		while( getline(ss, cur, '\n') ) {
			auto depth = cur.find_last_of("\t"); //Searches the string for the last character that matches any of the characters specified in its arguments.
			string name = (depth==string::npos)? cur : cur.substr(depth+1); //string::npos: string maximum length.
			if( cur.find(".") != string::npos) {
				result = max(result, path_len[depth-1] + (int) name.size());
			} else {
				path_len[depth] = path_len[depth-1] + (int) name.size() + 1;
			};
		}
		return result;
    }
};