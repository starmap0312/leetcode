#include <iostream>
#include <vector>

using namespace std;

class Interval {
public:
    int start;
    int end;
    Interval() : start(0), end(0) { }
    Interval(int s, int e) : start(s), end(e) { }
};

bool compare(Interval &a, Interval &b) {
    if (a.start < b.start) return true;
    if (a.start > b.start) return false;
    if (a.end < b.end) return true;
    return false;
}

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        vector<Interval> result; 
        if (intervals.size() == 0) return result;
        sort(intervals.begin(), intervals.end(), compare);
        int x = intervals[0].start, y = intervals[0].end;
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i].start <= y) {
                y = max(y, intervals[i].end);
            } else {
                result.push_back(Interval(x, y));
                x = intervals[i].start;
                y = intervals[i].end;
            }
        }
        result.push_back(Interval(x, y));
        return result;
    }
};

int main() {
    vector<Interval> intervals;
    intervals.push_back(Interval(1, 3));
    intervals.push_back(Interval(8, 10));
    intervals.push_back(Interval(2, 6));
    intervals.push_back(Interval(15, 18));
    Solution solution;
    vector<Interval> result = solution.merge(intervals);
    for (int i = 0; i < result.size(); i++)
        cout << result[i].start << "," << result[i].end << endl;
    return 0;
}
