// https://leetcode.com/problems/strobogrammatic-number-iii

class Solution {
public:
    int strobogrammaticInRange(string low, string high) {
        int n1 = low.size();
        int n2 = high.size();
        int count = 0;
        for(int n=n1; n<=n2; n++) {
            vector<string> strobeSet = findStrobogrammatic(n);
            for(auto res: strobeSet) {
                if(stoi(res)>=stoi(low) && stoi(res)<=stoi(high))
                    count++;
            };
        };
        return count;
    }

   unordered_map<char, char> mp;
    vector<string> findStrobogrammatic(int n) {
        mp['0'] = '0';
        mp['1'] = '1';
        mp['6'] = '9';
        mp['9'] = '6';
        mp['8'] = '8';
        return generateStroboNumbers(n, n);
    }
    vector<string> generateStroboNumbers(int n, int finalLength) {
        vector<string> res;
        if( n == 0 )
            return { "" };
        if( n == 1 )
            return { "0", "1", "8" };
        vector<string> prevStroboNums = generateStroboNumbers(n-2, finalLength);
        vector<string> curStrobeNums;
        for(string& prevStroboNum: prevStroboNums) {
            for(auto item: mp) {
                if(! (item.first == '0' && n == finalLength) ) { // for the final string, no leading zero.
                    //except when the current reversible pair is '00' and n == finalLength 
                    //(because we can't append '0' at the beginning of a number) and push this new number in ans. 
                    curStrobeNums.push_back(item.first + prevStroboNum + item.second);
                }
            }
        }
        return curStrobeNums;
    }

/*   int strobogrammaticInRange(string low, string high) {
        if(low == high) {
            if(isStrobogrammatic(low))
                return 1;
            else
                return 0;
        };
        int lowI = stoi(low);
        int highI = stoi(high);
        if(lowI > highI)
            return 0;
    
        int midI = lowI+(highI-lowI)/2;
        string mid = to_string(midI);
        int ret = 0;
        if(isStrobogrammatic(mid))
            ret++;
        return strobogrammaticInRange(low, to_string(midI-1)) + strobogrammaticInRange(to_string(midI+1), high)+ret;

    }
    bool isStrobogrammatic(string num) {
        string rotated_num;
        for(int i=num.length()-1; i>=0; i--) {
            if(num[i] == '0' || num[i] == '1' || num[i] == '8')
                rotated_num.push_back(num[i]);
            else if(num[i] == '6')
                rotated_num.push_back('9');
            else if(num[i] == '9')
                rotated_num.push_back('6');
            else
                return false;
        }
        return rotated_num == num;
    }*/
};