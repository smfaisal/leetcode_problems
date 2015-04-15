#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int trap(int A[], int n) {
    if (n < 3) {
      return 0;
    }

    vector<int> left(n);
    vector<int> right(n);
    left[0] = 0;
    int l = A[0];
    for (int i = 1; i < n; i++) {
      left[i] = l;
      if (A[i] > l) {
        l = A[i];
      }
    }
    right[n-1] = 0;
    int r = A[n-1];
    for (int i = n-2; i >= 0; i--) {
      right[i] = r;
      if (A[i] > r) {
        r = A[i];
      }
    }
    int total = 0;
    for (int i = 0; i < n; i++) {
      if (min(left[i], right[i]) - A[i] > 0) {
        total+= min(left[i], right[i]) - A[i];
      }
    }
    return total;
  }
};

int main() {
  Solution s;
  int A[] = {0,1,0,2,1,0,1,3,2,1,2,1};
  cout << "Total is: " << s.trap(A, 12) << endl;

  return 0;
}