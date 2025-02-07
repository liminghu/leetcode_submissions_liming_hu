// https://leetcode.com/problems/dot-product-of-two-sparse-vectors

/*Given two sparse vectors, compute their dot product.

Implement class SparseVector:

SparseVector(nums) Initializes the object with the vector nums
dotProduct(vec) Compute the dot product between the instance of SparseVector and vec
A sparse vector is a vector that has mostly zero values, you should store the sparse vector efficiently and compute the dot product between two SparseVector.

Follow up: What if only one of the vectors is sparse?
*/
class SparseVector {
public:
    unordered_map<int,int> sv; //idx, value
    int sz;

    SparseVector(vector<int> &nums) {
        int sz = nums.size();
        for(int i=0; i<sz; i++) {
            if(nums[i]!=0) 
                sv[i] = nums[i];
        }
        this->sz = sz;
        
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int res = 0;
        for(int i=0; i<vec.sz; i++) {
            if(vec.sv.find(i) != vec.sv.end() && this->sv.find(i) != this->sv.end())
                res += vec.sv[i] * this->sv[i];
        }
        return res;
        
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);