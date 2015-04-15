#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution{
public:
  static bool cmp(int a, int b) {
    return (a > b);
  }
  int maxnumber(int num) {
    vector<int> digits;

    int e = 1;
    int base = 10;
    while (num/e > 0) {
      digits.push_back((num/e)%10);
      e *= base;
    }
    // Got all digits, sort
    sort(digits.begin(), digits.end(), cmp);

    int res = 0;
    for (int i = 0; i < digits.size(); i++) {
      res = res*10+digits[i];
    }
    return res;
  }
};

int main() {
  Solution s;
  int n = 8754365;
  int res = s.maxnumber(n);
  cout << "max of " << n << " is: " << res << endl;
  return 0;
}