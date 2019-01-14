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
    vector<Interval> merge(vector<Interval>& intervals) {
        auto intervalLess = [] (const Interval & a, const Interval & b) -> bool {
            return a.start < b.start || a.start == b.start && a.end < b.end;
        };
        sort(intervals.begin(), intervals.end(), intervalLess);
        vector<Interval> ret;
        for (auto && interval : intervals)
        {
            if (!ret.empty() && ret.back().end >= interval.start)
                ret.back().end = max(ret.back().end, interval.end);
            else
                ret.push_back(interval);
        }
        return ret;
    }
};