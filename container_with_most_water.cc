#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxArea(vector<int> &height) {
    int area = 0;
    if (height.size() < 2) {
      return area;
    }
    int left = 0;
    int right = height.size()-1;
    int ar;
    while (left < right) {
      ar = (right-left) * min(height[right], height[left]);
      if (ar > area) {
        area = ar;
      }
      if (height[left] <= height[right]) {
        left++;
      } else {
        right--;
      }
    }

    return area;
  }
};

int main() {
  int a[] = {3, 5, 4, 6, 2};
  vector<int> v(a, a+5);
  Solution s;
  cout << "Max area: " << s.maxArea(v) << endl;
  return 0;
}