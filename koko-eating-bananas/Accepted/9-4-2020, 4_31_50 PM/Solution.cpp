// https://leetcode.com/problems/koko-eating-bananas

class Solution {
public:
   //Time: O(N*log(M))
    int minEatingSpeed(vector<int>& piles, int H) {
        int left = 1;
		int right = 1;
		//max(piles);
		for(int i=0; i<piles.size(); i++) {
			if (piles[i] > right )
				right = piles[i];
		}
		
		while(left < right) {
			int mid = left+(right-left)/2;
			//contidion
			if (canEatInTime(piles, mid, H)) {
				right = mid;
			} else {
			left = mid+1;
			}
		}
		
		return left;
    }
private:
bool canEatInTime(vector<int>& piles, int k, int H) {
	//
	int hours = 0;
	for (auto pile: piles) {
		int div = pile/k;
		hours += div;
		if(pile%k!=0) 
			hours++;
	}
	return hours <= H;
	}
};