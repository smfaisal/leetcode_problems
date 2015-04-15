#include <iostream>

using namespace std;

class Solution {
public:
  int hammingWeight(uint32_t n) {
    uint32_t mask = 1;
    int count = 0;
    for (int i = 0; i < sizeof(uint32_t)*8; i++) {
      if (n & mask<<i) {
        count++;
      }
    }
    return count;
  }
};

int main() {
  Solution s;
  uint32_t n = 11;
  int c = s.hammingWeight(n);
  cout << "Hamming Weight of " << n << " is: " << c << endl;
  return 0;
}