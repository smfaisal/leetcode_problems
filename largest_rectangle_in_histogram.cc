#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int largestRectangleArea(vector<int> &height) {
    int max_area = 0;
    int cur_height;
    int cur_len;
    if (height.empty()) {
      return max_area;
    }
    for (int i = 0; i < height.size(); i++) {
      cur_height = height[i];
      cur_len = 0;
      for (int j = 0; j < height.size(); j++) {
        if (height[j] >= cur_height) {
          cur_len++;
        } else {
          if (max_area < cur_len*cur_len) {
            max_area = cur_len*cur_height;
            cur_len = 0;
          }
        }
      }
    }
    return max_area;
  }
};

int main() {
  Solution s;
  int ht[] = {2, 1, 5, 6, 2, 3};
  vector<int> height(ht, ht+6);
  int area = s.largestRectangleArea(height);
  cout << "Max Area: " << area << endl;
  return 0;
}