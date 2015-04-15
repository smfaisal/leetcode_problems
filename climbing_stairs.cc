#include <iostream>

using namespace std;

class Solution {
public:
  void climb(int n, int& ways) {
    if (n == 0) {
      ways++;
      return;
    } else if (n < 0) {
      return;
    } else {
      climb(n-1, ways);
      if (n > 1) {
        climb(n-2, ways);
      }
    }
  }

  int climbStairs(int n) {
    int ways = 0;
    if (n < 2) {
      return n;
    }
    climb(n, ways);
    return ways;
  }
};

int main() {
  Solution s;
  int ways = s.climbStairs(38);
  cout << "Ways: " << ways << endl;
  return 0;
}