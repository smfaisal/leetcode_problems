#include <iostream>

using namespace std;

class Solution{
public:
  void toh(int d, int from, int mid, int to) {
    if (d == 1) {
      cout << from << " to " << to << endl;
      return;
    }
    toh(d-1, from, to, mid);
    cout << from << " to " << to << endl;
    toh(d-1, mid, from, to);
  }
};

int main() {
  Solution s;
  s.toh(3, 1, 2, 3);
  return 0;
}