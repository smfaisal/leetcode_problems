#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  int maxProduct(int A[], int n) {
    if (n == 1) {
      return A[0];
    }
    vector<vector<int> > prod(n, vector<int> (n, 1));
    int max_prod = 0;
    for (int i = 0; i < n; i++) {
      prod[i][i] = A[i];
      if (max_prod < A[i]) {
        max_prod = A[i];
      }
    }
    for (int len = 2; len <= n; len++) {
      for (int i = 0; i <= n-len; i++) {
        prod[i][i+len-1] = prod[i][i+len-2]*A[i+len-1];
        if (max_prod < prod[i][i+len-1]) {
          max_prod = prod[i][i+len-1];
        }
      }
    }
    return max_prod;
  }
};

int main() {
  int arr[] = {-2, 4, -2, 1, -5};
  Solution s;
  cout << "Max product: " << s.maxProduct(arr, 5) << endl;
  return 0;
}