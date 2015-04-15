#include <iostream>

using namespace std;

class Solution {
public:
  int jump(int A[], int n) {
    if (n < 2) {
      return 0;
    }

    int m = INT_MIN;
    int jmp = 0;
    int i = 0;
    while (i < n) {
      m = max(m, A[i]+i);
      if (m > 0) jmp++;
      if (m >= n-1) {
        return jmp;
      } else if (m == 0) {
        return -1;
      }
      int tmp = 0;
      for (int j = i+1; j <= m; j++) {
        if (j + A[j] > tmp) {
          tmp = j + A[j];
          i = j;
        }
      }
    }
//    min_jump[n-1] = 0;
//
//    for (int i = n-2; i >= 0; i--) {
//      if (n-1 - A[i] <= 0) {
//        min_jump[i] = 0;
//      } else {
//        m = INT_MAX;
//        for (int j=i+1; j <= i+A[i]; j++) {
//          m = min(min_jump[j], m);
//        }
//        min_jump[i] = 1+m;
//      }
//    }
    return jmp;
  }
};

int main() {
  Solution s;
  int A[] = {0, 1, 2, 3};
  cout << "Res: " << s.jump(A, 4) << endl;;
  return 0;
}