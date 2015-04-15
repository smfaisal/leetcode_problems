#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
public:
  int largestRectangleArea(vector<int> &height) {
    int max_area = 0;
    if (height.empty()) {
      return max_area;
    }
    height.push_back(0);
    int ind = 0;
    stack<int> stk;
    while (ind != height.size()) {
      if (stk.empty() || height[ind] >= height[stk.top()]) {
        stk.push(ind++);
      } else {
        int h = height[stk.top()];
        stk.pop();
        max_area = max(max_area, (stk.empty())?h*ind:h*(ind-stk.top()-1));
      }
    }

    height.pop_back();
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