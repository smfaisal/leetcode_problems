#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int firstMissingPositive(int A[], int n) {
    if (n==0) {
      return 1;
    }
    int k = -1;
    int tmp;
    for (int i = 0; i < n; i++) {
      if (A[i] <= 0) {
        if (k < i-1) {
          tmp = A[i];
          A[i] = A[k+1];
          A[k+1] = tmp;
        }
        k++;
      }
    }
    for (int i = 0; i < n; i++) {
      cout << "A: " << A[i] << endl;
    }
    vector<int> t(A+k+1, A+n);
    int n_st = k+1;
    for (int i = n_st; i < n; i++) {
//      cout << "A[" << i << "]: " << A[i] << endl;
      if (A[i] > 0 && A[i] <= n-n_st) {
        t[A[i]-1] = -A[i];
      }
    }
    int i;
    for (i = 0; i < n-n_st; i++) {
      cout << "t[" << i << "]: " << t[i] << endl;
      if (t[i] >= 0) {
        return i+1;
      }
    }
    return i+1;
  }
};

int main() {
  Solution s;
  int a[] = {1, 0};
  cout << "Missing: " << s.firstMissingPositive(a, 2) << endl;
  return 0;
}