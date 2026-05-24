class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        std::priority_queue<pair<int, pair<int, int>>, 
            std::vector<pair<int, pair<int, int>>>, 
            std::less<pair<int, pair<int, int>>>> maxHeap;

        for (auto& point : points){
            int x1 = point[0];
            int y1 = point[1];
            int distance = x1*x1 + y1*y1;
            maxHeap.push({distance, {x1, y1}});
            if (maxHeap.size() > k){
                maxHeap.pop();
            }
        }

        std::vector<vector<int>> res;

        while (!maxHeap.empty()){
            res.push_back({maxHeap.top().second.first,
                           maxHeap.top().second.second});
            maxHeap.pop();
        }

        return res;
    }
};
