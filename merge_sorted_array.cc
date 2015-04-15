#include <iostream>

using namespace std;

class Solution {
public:
  void merge(int A[], int m, int B[], int n) {
    if (n == 0) {
      return;
    }
    if (m == 0) {
      n--;
      while (n >= 0) {
        A[n] = B[n];
        n--;
      }
    }

    int p = m+n-1;

    while (p >= 0) {
      if (A[m-1] >= B[n-1]) {
        A[p--] = A[m-1];
        m--;
      } else {
        A[p--] = B[n-1];
        n--;
      }
      if (m < 1 || n < 1) {
        break;
      }
    }
//    cout << "m: " << m << " n: " << n << " p: " << p << endl;
    if (m > 0) {
      while (m > 0) {
        A[p--] = A[m-1];
        m--;
      }
    } else {
      while (n > 0) {
        A[p--] = B[n-1];
        n--;
      }
    }
    return;
  }
};

int main() {
  Solution s;
  int a[5] = {1, 5, 10, 15};
  int b[] = {55};

  for (int i = 0; i < 5; i++) {
    cout << a[i] << ", ";
  }
  cout << endl;
  s.merge(a, 4, b, 1);

  for (int i = 0; i < 5; i++) {
    cout << a[i] << ", ";
  }
  cout << endl;
}