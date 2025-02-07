// https://leetcode.com/problems/sort-an-array

class Solution {

public:
    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size()-1);
        vector<int> res;
        res = nums;
        return res;
    }

int partition(vector<int>& nums, int start, int end)
{
    int pivot = nums[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (nums[i] <= pivot)
            count++;
    }
 
    // Giving pivot element its correct position
    int pivotIndex = start + count;
    swap(nums[pivotIndex], nums[start]);
 
    // Sorting left and right parts of the pivot element
    int i = start, j = end;
 
    while (i < pivotIndex && j > pivotIndex) {
 
        while (nums[i] <= pivot) {
            i++;
        }
 
        while (nums[j] > pivot) {
            j--;
        }
 
        if (i < pivotIndex && j > pivotIndex) {
            swap(nums[i++], nums[j--]);
        }
    }
 
    return pivotIndex;
}

void swap(int& a, int& b){
        int tmp = a;
        a = b;
        b = tmp;
}

void quickSort(vector<int>& nums, int start, int end)
{
    // base case
    if (start >= end)
        return;
    // partitioning the array
    int p = partition(nums, start, end);
    // Sorting the left part
    quickSort(nums, start, p - 1);
    // Sorting the right part
    quickSort(nums, p + 1, end);
}
};