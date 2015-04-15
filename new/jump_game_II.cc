#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int jump(int A[], int n) {
    if (n == 1) {
      return 0;
    }

    int i = 0;
    int jmp = 0;
    int m = INT_MIN;
    while (i < n) {
      m = max(m, A[i]+i);
      if (m > 0) {
        jmp++;
      }
      if (m >= n-1) {
        return jmp;
      }

      int t = INT_MIN;
      for (int j = i+1; j <= m; j++) {
        if (j+A[j] > t) {
          t = j+A[j];
          i = j;
        }
      }
    }
    return jmp;
//    vector<int> steps(n);
//    steps[n-1] = 0;
//    int min = INT_MAX;
//    for (int i = n-2; i >= 0; i--) {
//      min = INT_MAX;
//      for (int j = 1; j <= A[i]; j++) {
//        if (steps[j] < min) {
//          min = steps[j];
//        }
//      }
//      steps[i] = min+1;
//    }
//    return steps[0];
  }
};

int main() {
  Solution s;
  int A[] = {2,3,1,1,4};
  cout << "Res: " << s.jump(A, 5) << endl;;
  return 0;
}