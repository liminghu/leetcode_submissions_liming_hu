// https://leetcode.com/problems/kth-largest-element-in-a-stream

/*Design a class to find the kth largest element in a stream. Note that it is the kth largest element 
in the sorted order, not the kth distinct element.
Implement KthLargest class:

KthLargest(int k, int[] nums) Initializes the object with the integer k and the stream of integers nums.
int add(int val) Appends the integer val to the stream and returns the element representing the kth 
largest element in the stream.
*/
class KthLargest {
private:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq_min;
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int i=0; i<nums.size(); i++) {
             if(pq_min.size() < k) 
                pq_min.push(nums[i]);
            else { //pq_min size is k. so the top is the kth largest.
                int kthElem = pq_min.top();
                if(nums[i] <= kthElem) {
                    continue;
                } else { //nums[i] > kthElem
                    pq_min.pop();
                    pq_min.push(nums[i]);
                }
            }
 
        }   
    }
    
    int add(int val) {
        if(pq_min.size() < k) 
            pq_min.push(val);
        else { //pq_min size is k. so the top is the kth largest.
            int kthElem = pq_min.top();
            if(val > kthElem) {
                    pq_min.pop();
                    pq_min.push(val);
            }
        }
        return pq_min.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */