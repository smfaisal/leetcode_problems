#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void rotate(int nums[], int n, int k) {
    k = k%n;
    if (k == 0) {
      return;
    }

    int* temp = (int* ) malloc(sizeof(int)*k);
    int tmp_ind = k-1;
    for (int i = n-1; i >= n-k; i--) {
      temp[tmp_ind--] = nums[i];
    }
    for (int i = n-k-1; i >= 0; i--) {
      nums[i+k] = nums[i];
    }
    for (int i = 0; i < k; i++) {
      nums[i] = temp[i];
    }
    free(temp);
  }
};

int main() {
  Solution s;
  int a[] = {5, 6, 1, 2, 3, 4};

  for (int i = 0; i < 6; i++) {
    cout << a[i] << ", ";
  }
  cout << endl;

  s.rotate(a, 6, 8);

  for (int i = 0; i < 6; i++) {
    cout << a[i] << ", ";
  }
  cout << endl;
  return 0;
}