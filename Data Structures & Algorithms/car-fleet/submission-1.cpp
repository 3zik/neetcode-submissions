class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        // strategy is to create a vector of pair of ints that store position and speed
        // then you go backwards counting fleets (so )


        int n = position.size();

        vector<pair<int, int>> pns;

        for (int i = 0; i < n; ++i) {
            pns.push_back({position[i], speed[i]});
        }
        sort(pns.rbegin(), pns.rend());

        int fleets = 1;
        double prevTime = (double) (target - pns[0].first) / pns[0].second;

        for (int i = 1; i < n; ++i){
            double currTime = (double) (target - pns[i].first) / pns[i].second;
            if (currTime > prevTime) {
                fleets++;
                prevTime = currTime;
            }
        }
        return fleets;
    }
};
