#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for a point.
 */
struct Point {
  int x;
  int y;
  Point() : x(0), y(0) {}
  Point(int a, int b) : x(a), y(b) {}
};

class Solution {
  public:
  int maxPoints(vector<Point> &points) {
    if (points.size() <= 2) {
      return points.size();
    }
    int max = 0;
    vector<double> slopes;

    for (int i = 0; i < points.size(); i++) {
      int dup = 1;
      slopes.clear();
      for (int j = 0; j < points.size(); j++) {
        if (i != j) {
          if (points[i].x-points[j].x == 0) {
            if (points[i].y-points[j].y == 0) {
              dup++;
            } else {
              slopes.push_back(99999);
            }
          } else {
            slopes.push_back(10000 * (points[i].y-points[j].y)/(points[i].x-points[j].x));
          }
        }
      }

      sort(slopes.begin(), slopes.end());

      int len = 1;
      if (slopes.size() == 0) {
        len = 0;
      }
      for (int i = 1; i < slopes.size(); i++) {
        if (slopes[i] == slopes[i-1]) {
          len++;
        } else {
          if (len + dup > max) {
            max = len + dup;
          }
          len = 1;
        }
      }
      if (len + dup > max) {
        max = len + dup;
      }
    }
    return max;
  }
};

int main() {
  vector<Point> points;
  points.push_back(Point(0,9));
  points.push_back(Point(138,429));
  points.push_back(Point(115,359));
  points.push_back(Point(115,359));
  points.push_back(Point(-30,-102));
  points.push_back(Point(230,709));
  points.push_back(Point(-150,-686));
  points.push_back(Point(-135,-613));
  points.push_back(Point(-60,-248));
  points.push_back(Point(-161,-481));
  points.push_back(Point(207,639));
  points.push_back(Point(23,79));
  points.push_back(Point(-230,-691));
  points.push_back(Point(-115,-341));
  points.push_back(Point(92,289));
  points.push_back(Point(60,336));
  points.push_back(Point(-105,-467));
  points.push_back(Point(135,701));
  points.push_back(Point(-90,-394));
  points.push_back(Point(-184,-551));
  points.push_back(Point(150,774));

  /**
   Point a(1, 1);
   Point b(1, 1);
   Point c(1, 1);
   points.push_back(a);
   points.push_back(b);
   points.push_back(c);
   */

  Solution s;
  int max = s.maxPoints(points);

  cout << "Max points: " << max << endl;
}