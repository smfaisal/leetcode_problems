#include <iostream>

using namespace std;

class Solution {
public:
  int trap(int A[], int n) {
    if (n < 2) {
      return 0;
    }
    int* left = (int*) malloc(n*sizeof(int));
    int* right = (int*) malloc(n*sizeof(int));

    left[0] = 0;
    for (int i = 1; i < n; i++) {
      left[i] = max(left[i-1], A[i-1]);
    }
    right[n-1] = 0;
    for (int i = n-2; i >=0; i--) {
      right[i] = max(right[i+1], A[i+1]);
    }

    int res = 0;
    int min = 0;
    for (int i = 0; i < n; i++) {
      min = std::min(left[i], right[i]);
      min -= A[i];
      if (min > 0) {
        res+= min;
      }
    }
    free(left);
    free(right);
    return res;
  }
};

int main() {
  Solution s;
  int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << "Total is: " << s.trap(A, 12) << endl;

  return 0;
}