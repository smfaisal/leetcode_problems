#include <iostream>

using namespace std;

class Solution {
public:
  int sqrt(int x) {
    if (x < 1) {
      return 0;
    } else if (x == 1) {
      return 1;
    }

    long long low = 0;
    long long high = x;
    long long mid = low + (high-low)/2;

    while (high-low > 1) {
      mid = low + (high-low)/2;
      if (mid*mid == x) {
        return mid;
      }
      if (mid*mid < x) {
        low = mid;
      } else {
        high = mid;
      }
    }
    return low;
  }
};

int main() {
  Solution s;
  int root = s.sqrt(11);
  cout << "Sqrt: " << root << endl;
  return 0;
}