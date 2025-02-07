// https://leetcode.com/problems/divide-players-into-teams-of-equal-skill

class Solution {
public:
    long long dividePlayers(vector<int>& skill) {//1 <= skill[i] <= 1000
        int n = skill.size(); //even
        // n/2 teams size 2
        int totalSkill = 0;
        vector<int> skillFrequency(2001, 0);
        for(int playerskill: skill) {
            totalSkill += playerskill;
            skillFrequency[playerskill]++;
        };
        if(totalSkill% (n/2) != 0)
            return -1;
        int totalTeamSkill = totalSkill / (n/2);
        long long totalChemistry = 0;
        for(int playerskill: skill) {
            //skillFrequency[playerskill]--;
            int partnerSkill = totalTeamSkill - playerskill;
            if(skillFrequency[partnerSkill] == 0)
                return -1;
            totalChemistry += (long long)playerskill * (long long)partnerSkill;
            skillFrequency[partnerSkill]--;
        };
        return totalChemistry/2;

    }
};