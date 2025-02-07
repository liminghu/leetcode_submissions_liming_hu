// https://leetcode.com/problems/range-sum-query-mutable

/*
Given an integer array nums, handle multiple queries of the following types:

Update the value of an element in nums.
Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
Implement the NumArray class:

NumArray(int[] nums) Initializes the object with the integer array nums.
void update(int index, int val) Updates the value of nums[index] to be val.
int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
*/
class SegmentTreeNode {
public:
  SegmentTreeNode(int start, int end, int sum,
                  SegmentTreeNode* left = nullptr,
                  SegmentTreeNode* right = nullptr): 
    start(start),
    end(end),
    sum(sum),
    left(left),
    right(right){}      
  ~SegmentTreeNode() {
    delete left;
    delete right;
    left = right = nullptr;
  }
  
  int start;
  int end;
  int sum;
  SegmentTreeNode* left;
  SegmentTreeNode* right;
};

class NumArray {
private:
  vector<int> nums_;
  SegmentTreeNode* root_ =  new SegmentTreeNode(0, 0, 0);
  
  SegmentTreeNode* buildTree(int start, int end) {  
    if (start == end) {      
      return new SegmentTreeNode(start, end, nums_[start]);
    }
    int mid = start + (end - start) / 2;
    auto left = buildTree(start, mid);
    auto right = buildTree(mid + 1, end);
    auto node = new SegmentTreeNode(start, end, left->sum + right->sum, left, right);    
    return node;
  }
  
  void updateTree(SegmentTreeNode* root, int i, int val) {
    if (root->start == i && root->end == i) {
      root->sum = val;
      return;
    }
    int mid = root->start + (root->end - root->start) / 2;
    if (i <= mid) {
      updateTree(root->left, i, val);
    } else {      
      updateTree(root->right, i, val);
    }
    root->sum = root->left->sum + root->right->sum;
  }
  
  int sumRange(SegmentTreeNode* root, int i, int j) {    
    if (i == root->start && j == root->end) {
      return root->sum;
    }
    int mid = root->start + (root->end - root->start) / 2;
    if (j <= mid) {
      return sumRange(root->left, i, j);
    } else if (i > mid) {
      return sumRange(root->right, i, j);
    } else {
      return sumRange(root->left, i, mid) + sumRange(root->right, mid + 1, j);
    }
  }

public:
    NumArray(vector<int>& nums) { //1 <= nums.length <= 3 * 104
                                    //-100 <= nums[i] <= 100
                                    //0 <= index < nums.length
                                    //-100 <= val <= 100
                                    //0 <= left <= right < nums.length
                                    //At most 3 * 104 calls will be made to update and sumRange.
    nums_ = nums; //nums_.swap(nums);
    if (!nums_.empty())
      root_ = buildTree(0, nums_.size() - 1); 
  }
 
  void update(int i, int val) {
    updateTree(root_, i, val); 
  }
 
  int sumRange(int i, int j) {
    return sumRange(root_, i, j); 
  }
};
/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */