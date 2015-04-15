#include <iostream>
#include <vector>

using namespace std;

// Definition for an interval.
struct Interval {
  int start;
  int end;
  Interval() : start(0), end(0) {}
  Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
  int find_overlap(vector<Interval>& res, Interval& val) {
    for (int i = 0; i < res.size(); i++) {
      if ((val.start >= res[i].start && val.start <= res[i].end) ||
          (val.end >= res[i].start && val.end <= res[i].end) ||
          (val.start <= res[i].start && val.end >= res[i].end)) {
        return i;
      }
    }
    return -1;
  }

  vector<Interval> merge(vector<Interval> &intervals) {
    vector<Interval> result;
    if (intervals.size() == 0) {
      return result;
    }
    result.push_back(intervals[0]);
    for (int i = 1; i < intervals.size(); i++) {
      int ind = find_overlap(result, intervals[i]);
      if (ind > -1) {
        result[ind].start = min(result[ind].start, intervals[i].start);
        result[ind].end = max(result[ind].end, intervals[i].end);
      } else {
        result.push_back(intervals[i]);
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  vector<Interval> intervals;
  intervals.push_back(Interval(1, 3));
  intervals.push_back(Interval(0, 6));
  intervals.push_back(Interval(8, 10));
  intervals.push_back(Interval(15, 18));

  vector<Interval> result = s.merge(intervals);
  cout << "Result: " << endl;
  for (int i = 0; i < result.size(); i++) {
    cout << "[" << result[i].start << ", " << result[i].end << "]" << endl;
  }

  return 0;
}