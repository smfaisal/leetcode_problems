#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxProduct(int A[], int n) {
    int max_so_far = A[0];
    int maxProduct = A[0];
    int minProduct = A[0];

    for (int i = 1; i < n; i++) {
      int tmpmax = maxProduct;
      maxProduct = max(max(maxProduct*A[i], minProduct*A[i]), A[i]);
      minProduct = min(min(tmpmax*A[i], minProduct*A[i]), A[i]);
      if (max_so_far < maxProduct) {
        max_so_far = maxProduct;
      }
//      if (A[i] > 0) {
//        maxProduct = maxProduct * A[i];
//        minProduct = min(minProduct * A[i], 1);
//      } else if (A[i] == 0) {
//        maxProduct = 1;
//        minProduct = 1;
//      } else {
//        int tmp = maxProduct;
//        maxProduct = max(minProduct * A[i], 1);
//        minProduct = tmp*A[i];
//      }
//      if (maxProduct > max_so_far) {
//        max_so_far = maxProduct;
//      }
    }
    return max_so_far;
  }
};

int main() {
  int arr[] = {-2, 4, -2, 1, -5};
  Solution s;
  cout << "Max product: " << s.maxProduct(arr, 5) << endl;
  return 0;
}