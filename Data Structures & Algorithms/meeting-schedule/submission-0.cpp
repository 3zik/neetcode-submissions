/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        // 1. sort all "starts".
        // 2. if each start is greater than end before it, its ok

        for (int i = 0; i<intervals.size(); ++i){
            std::sort(intervals.begin(), intervals.end(), [](auto&x, auto& y){
                return x.start < y.start;
            });
        }
        for (int i = 1; i < intervals.size(); ++i){
            if (intervals[i].start < intervals[i - 1].end){
                return false;
            }
        }
        return true;
    }
};
