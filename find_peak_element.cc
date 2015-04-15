#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int peak(const vector<int>& num, int l, int r) {
    if (l == r) {
      return l;
    }
    int m = (l+r)/2;

    if (m == l) {
      if (num[m] > num[m+1]) {
        return m;
      } else {
        return peak(num, m+1, r);
      }
    } else if (m == r) {
      if (num[m] > num[m-1]) {
        return m;
      } else {
        return peak(num, l, m-1);
      }
    } else if (num[m] > num[m-1] && num[m] > num[m+1]) {
      return m;
    } else if (num[m] < num[m-1]) {
      return peak(num, l, m-1);
    } else {
      return peak(num, m+1, r);
    }
  }

  int findPeakElement(const vector<int> &num) {
    if (num.size() == 1) {
      return 0;
    }
    int p = peak(num, 0, num.size()-1);
    return p;
  }
};

int main() {
  int a[] = {3, 4, 1, 34, 12, 189};
  vector<int> num(a, a+6);
  Solution s;

  int p = s.findPeakElement(num);

  cout << "Peak element at: " << p << endl;
  return 0;
}