#include <iostream>
#include <cmath>

using namespace std;

class Solution {
public:
  int trailingZeroes(int n) {
    if (n < 5) {
      return 0;
    }
    return trailingZeroes(n/5) + n/5;
  }
};

int main() {
  Solution s;
  int z = s.trailingZeroes(500000);

  cout << "Trailing zeroes: " << z << endl;

  return 0;
}