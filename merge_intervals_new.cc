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
  static bool mycomp(const Interval& l, const Interval& r) {
    return (l.start < r.start);
  }

  vector<Interval> merge(vector<Interval> &intervals) {
    vector<Interval> result;
    if (intervals.size() == 0) {
      return result;
    }
    sort(intervals.begin(), intervals.end(), mycomp);
    int ind = 0;
    result.push_back(intervals[ind]);
    for (int i = 1; i < intervals.size(); i++) {
      if (intervals[i].start <= result[ind].end) {
        result[ind].end = max(result[ind].end, intervals[i].end);
      } else {
        result.push_back(intervals[i]);
        ind++;
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  vector<Interval> intervals;
  intervals.push_back(Interval(1, 3));
  intervals.push_back(Interval(2, 6));
  intervals.push_back(Interval(8, 10));
  intervals.push_back(Interval(0, 18));

  vector<Interval> result = s.merge(intervals);
  cout << "Result: " << endl;
  for (int i = 0; i < result.size(); i++) {
    cout << "[" << result[i].start << ", " << result[i].end << "]" << endl;
  }
  return 0;
}
