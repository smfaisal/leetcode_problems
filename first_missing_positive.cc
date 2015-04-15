#include <iostream>

using namespace std;

class Solution {
public:
  int segregate(int A[], int n) {
    int i = 0;
    int temp;
    for (int j = 0; j < n; j++) {
      if (A[j] <= 0) {
        temp = A[i];
        A[i] = A[j];
        A[j] = temp;
        i++;
      }
    }
    return i;
  }

  int missing(int* a, int n) {
    int i = 0;
    for (i = 0; i < n; i++) {
      if (abs(a[i]) <= n && a[abs(a[i])-1] > 0) {
        a[abs(a[i])-1] = -a[abs(a[i])-1];
      }
    }
    for (i = 0; i < n; i++) {
      if (a[i] > 0) {
        return i+1;
      }
    }
    return i+1;
  }

  int firstMissingPositive(int A[], int n) {
    if (n == 0) {
      return 1;
    } else if (n == 1) {
      if (A[0] == 1) {
        return 2;
      } else {
        return 1;
      }
    }

    int new_start = segregate(A, n);
    return missing(&A[new_start], n-new_start);
  }

};

int main() {
  Solution s;
  int a[] = {1, 0};
  cout << "Missing: " << s.firstMissingPositive(a, 2) << endl;
  return 0;
}