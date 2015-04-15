#include <iostream>

using namespace std;

class Solution {
public:
  void qsort(int A[], int p, int q) {
    if (p >= q) {
      return;
    }
    int num = A[q];
    int ind = p-1;
    for (int i = p; i < q; i++) {
      if (A[i] < num) {
        ind++;
        int tmp = A[ind];
        A[ind] = A[i];
        A[i] = tmp;
      }
    }
    ind++;
    int tmp = A[ind];
    A[ind] = num;
    A[q] = tmp;
    qsort(A, p, ind-1);
    qsort(A, ind+1, q);
  }

  void sortColors(int A[], int n) {
    if (n < 2) {
      return;
    }
    qsort(A, 0, n-1);
  }
};

int main() {
  int A[] = {1, 0, 1, 1, 2, 1, 2, 0, 0, 2, 1};

  Solution s;

  s.sortColors(A, 11);

  for (int i = 0; i < 11; i++) {
    cout << A[i] << ", " ;
  }
  cout << endl;
}