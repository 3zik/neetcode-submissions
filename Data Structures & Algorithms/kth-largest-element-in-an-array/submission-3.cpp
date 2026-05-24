class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        std::priority_queue<int, 
            std::vector<int>, greater<int>> minHeap;
        for (const int& num : nums){
            minHeap.push(num);
            if (minHeap.size() > k) {
                minHeap.pop();
            }
        }
        return minHeap.top();
    }
};
