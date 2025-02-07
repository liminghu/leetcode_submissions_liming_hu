// https://leetcode.com/problems/maximum-points-after-enemy-battles

class Solution {
public:
    long long maximumPoints(vector<int>& enemyEnergies, int currentEnergy) { //1 <= enemyEnergies.length <= 105
                                                                            //1 <= enemyEnergies[i] <= 109
                                                                            //0 <= currentEnergy <= 109
        int sz = enemyEnergies.size();
        
        int maxPoints = 0;
        
        sort(enemyEnergies.begin(), enemyEnergies.end());
        vector<bool> marked(sz, false); // initialize as all unmarked.
        int lowIndex = 0; 
        int highIndex = sz-1;
        while(lowIndex <= highIndex) {
            /* Choose an unmarked enemy, i, such that currentEnergy >= enemyEnergies[i]. By choosing this option:
            You gain 1 point.
                Your energy is reduced by the enemy's energy, i.e. currentEnergy = currentEnergy - enemyEnergies[i].
            
            If you have at least 1 point, you can choose an unmarked enemy, i. By choosing this option:
            Your energy increases by the enemy's energy, i.e. currentEnergy = currentEnergy + enemyEnergies[i].
            The enemy i is marked.*/
            if( marked[ lowIndex ] ) {
                lowIndex++;
                continue;
            }
            
            if( lowIndex >= sz)
                break;
            
            while(currentEnergy >= enemyEnergies[lowIndex]) {
                maxPoints++;
                currentEnergy = currentEnergy - enemyEnergies[lowIndex];
            };
            
            while(highIndex >=0 && marked[ highIndex ] ) {
                highIndex--;
            };
            if(highIndex < 0)
                break;
            
            if( maxPoints >= 1 ) {
                currentEnergy = currentEnergy + enemyEnergies[highIndex];
                marked[highIndex] = true;
                highIndex--;
            }
        }
        
        return maxPoints;
        
    }
    
 
};