#include <iostream>

using namespace std;

class Solution {
public:
  bool canJump(int A[], int n) {
    if (n < 2) {
      return true;
    }
    int jump_size = 0;
    int pos = 0;

    while (pos < n) {
      jump_size = max(jump_size, pos+A[pos]);
      if (jump_size >= n-1) {
        return true;
      }
      if (jump_size == pos) {
        return false;
      }
      int tmp = -1;
      for (int i = pos+1; i <= jump_size; i++) {
        if (tmp < i+A[i]) {
          tmp = i+A[i];
          pos = i;
        }
      }
    }
    return false;
  }
};

int main() {
  Solution s;
  int a[] = {5,4,1,1,0,0,7};
  cout << "Can jump? " << s.canJump(a, 7) << endl;
  return 0;
}