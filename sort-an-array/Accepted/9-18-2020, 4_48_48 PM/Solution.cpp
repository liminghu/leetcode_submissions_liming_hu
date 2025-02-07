// https://leetcode.com/problems/sort-an-array


class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        //quick sort.
		function<void(int, int)> quicksort = [&](int l, int r) {
			if (l >=r) return;
			int i=l;
			int j=r;
			int p = nums[l+rand()%(r-l+1)];
			while(i<=j) {
				while(nums[i]<p) i++;
				while(nums[j]>p) j--;
				if(i<=j) {
					swap(nums[i], nums[j]);
					i++;
					j--;
				}
			}
			quicksort(l,j);
			quicksort(i,r);
		};
		quicksort(0, nums.size()-1);
		return nums;
    }
};