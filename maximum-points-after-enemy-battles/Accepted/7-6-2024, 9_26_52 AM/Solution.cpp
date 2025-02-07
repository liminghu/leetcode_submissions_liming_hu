// https://leetcode.com/problems/maximum-points-after-enemy-battles

class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) { //1 <= enemyEnergies.length <= 105
                                                                            //1 <= enemyEnergies[i] <= 109
                                                                            //0 <= currentEnergy <= 109
        int sz = enemyEnergies.size();
        
        long long  maxPoints = 0;
        
        sort(enemyEnergies.begin(), enemyEnergies.end());
        if(currentEnergy < enemyEnergies[0])
            return 0;
        int lowIndex = 0; 
        int highIndex = sz-1;
        while(0 <= highIndex) {
            /* Choose an unmarked enemy, i, such that currentEnergy >= enemyEnergies[i]. By choosing this option:
            You gain 1 point.
                Your energy is reduced by the enemy's energy, i.e. currentEnergy = currentEnergy - enemyEnergies[i].
            
            If you have at least 1 point, you can choose an unmarked enemy, i. By choosing this option:
            Your energy increases by the enemy's energy, i.e. currentEnergy = currentEnergy + enemyEnergies[i].
            The enemy i is marked.*/
            if(currentEnergy >= enemyEnergies[0]) {
                maxPoints+=currentEnergy/enemyEnergies[0];
                currentEnergy %= enemyEnergies[0];
            };
            
            if( maxPoints >= 1 ) {
                currentEnergy = currentEnergy + enemyEnergies[highIndex];
                highIndex--;
            }
        }
        
        return maxPoints;
        
    }
    
 
};