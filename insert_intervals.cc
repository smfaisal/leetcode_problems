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
  vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> result;
    if (intervals.size() == 0) {
      result.push_back(newInterval);
      return result;
    }
    int i = 0;
    while (i < intervals.size()) {
      if (intervals[i].start < newInterval.start) {
        result.push_back(intervals[i++]);
      } else {
        break;
      }
    }
    result.push_back(newInterval);
    while (i < intervals.size()) {
      result.push_back(intervals[i++]);
    }

    i = 1;
    int r_ind = 0;
    while (i < result.size()) {
      if (result[i].start <= result[r_ind].end) {
        result[r_ind].end = max(result[r_ind].end, result[i].end);
      } else {
        r_ind++;
        result[r_ind] = result[i];
      }
      i++;
    }
    result.resize(r_ind+1);
    return result;
  }
};

int main() {
  Solution s;
  vector<Interval> intervals;
  intervals.push_back(Interval(1, 3));
  intervals.push_back(Interval(2, 6));
  intervals.push_back(Interval(8, 10));
  intervals.push_back(Interval(12, 18));

  vector<Interval> result = s.insert(intervals, Interval(0, 10));
  cout << "Result: " << endl;
  for (int i = 0; i < result.size(); i++) {
    cout << "[" << result[i].start << ", " << result[i].end << "]" << endl;
  }
  return 0;
}
