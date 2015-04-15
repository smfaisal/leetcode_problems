#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    if (height.size() < 2) {
      return 0;
    }
    int area = INT_MIN;
    int st = 0;
    int end = height.size()-1;
    int marea = INT_MIN;
    while (st < end) {
      area = (end-st) * min(height[end], height[st]);
      if (area > marea) {
        marea = area;
      }
      if (height[st] < height[end]) {
        st++;
      } else {
        end--;
      }
    }
    return marea;
  }
};

int main() {
  int a[] = {3, 5, 4, 6, 2};
  vector<int> v(a, a+5);
  Solution s;
  cout << "Max area: " << s.maxArea(v) << endl;
  return 0;
}
