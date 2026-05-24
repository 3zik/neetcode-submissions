class KthLargest {
public:
    int k;
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap;

    KthLargest(const int k, vector<int>& nums) : k(k) {
        for(int num : nums){
            minHeap.push(num);
            if (minHeap.size() > k){
                minHeap.pop();
            }
        }
    }
    
    int add(int val) {
        minHeap.push(val);
        while (minHeap.size() > k) {
            minHeap.pop();
        }
        return minHeap.top(); 
    }
};
