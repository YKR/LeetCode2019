/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> ret;
        auto insertInterval = [&ret] (Interval & interval) -> void {
            if (!ret.empty() && ret.back().end >= interval.start)
                ret.back().end = max(ret.back().end, interval.end);
            else
                ret.push_back(interval);
        };
        bool inserted = false;
        for (auto && interval : intervals)
        {
            if (newInterval.start <= interval.start)
            {
                insertInterval(newInterval);
                inserted = true;
            }
            insertInterval(interval);
        }
        if (!inserted) insertInterval(newInterval);
        return ret;
    }
};