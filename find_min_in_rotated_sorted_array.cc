#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int getMin(vector<int>& num, int st, int end) {
    if (st > end) {
      return INT_MAX;
    } else if (st == end) {
      return num[st];
    } else if (end-st < 2) {
      return min(num[st], num[end]);
    }

    int mid = (st+end)/2;
    if (num[mid] < num[mid-1]) {
      return num[mid];
    } else if (num[mid] > num[mid+1]) {
      return num[mid+1];
    } else {
      if (num[mid] > num[end]) {
        return getMin(num, mid+1, end);
      } else {
        return getMin(num, st, mid-1);
      }
    }
  }

  int findMin(vector<int> &num) {
    if (num.size() == 1) {
      return num[0];
    }
    // find switch
    return getMin(num, 0, num.size()-1);
  }
};

int main() {
  int a[] = {15, 18, 20, 21, 25, 28, 30, 12};
  Solution s;
  vector<int> num(a, a+8);

  cout << "Min: " << s.findMin(num) << endl;
  return 0;
}