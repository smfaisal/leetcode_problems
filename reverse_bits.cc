#include <iostream>

using namespace std;

class Solution {
public:
  uint32_t reverseBits(uint32_t n) {
    uint32_t res = 0;
    uint32_t mask = 1;

    for (int i = 0; i < sizeof(uint32_t)*8; i++) {
      if (n & mask<<i) {
        res |= 1 << (sizeof(uint32_t)*8-1-i);
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  uint32_t n = 43261596;
  uint32_t res;
  res = s.reverseBits(n);
  cout << "Reverse Bits of " << n << " is: " << res << endl;
  return 0;
}

