class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        std::priority_queue<int, std::vector<int>, less<int>> maxHeap;
        for (int stone : stones){
            maxHeap.push(stone);
        }
        while(maxHeap.size() > 1){
            int a = maxHeap.top();
            maxHeap.pop();
            if (a > maxHeap.top()){
                int b = maxHeap.top();
                maxHeap.pop();
                maxHeap.push(a-b);
            } else {
                maxHeap.pop();
            }
        }
        return maxHeap.size() ? maxHeap.top() : 0;
    }
};
