#include <iostream>

using namespace std;

class Solution {
public:
  double pow(double x, int n) {
    if (n == 0) {
      return 1;
    }
    double res = 1;
    double num = x;
    int p = abs(n);

    while (p > 0) {
      if (p % 2 == 1) {
        res = res * num;
      }
      num = num * num;
      p = p/2;
    }

    if (n > 0) {
      return res;
    } else {
      return double(1)/res;
    }
  }
};

int main() {
  Solution s;
  cout << "2^-8 is: " << s.pow(2, -8) << endl;
  return 0;
}