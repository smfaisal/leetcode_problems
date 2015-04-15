#include <iostream>

using namespace std;

class Solution {
public:
  int removeDuplicates(int A[], int n) {
    if (n < 3) {
      return n;
    }
    int next = 0;
    int same = 0;
    for (int i = 1; i < n; i++) {
      if (A[i] != A[i-1]) {
        same = 0;
        next++;
        if (i != next) {
          A[next] = A[i];
        }
      } else {
        same++;
        if (same < 2) {
          next++;
          if (i != next) {
            A[next] = A[i];
          }
        }
      }
    }
    return next+1;
  }
};

int main() {
  Solution s;
  int arr[] = {1, 1, 2, 3, 3, 3, 4, 5, 5, 5, 5, 5, 5, 10, 10, 10};
  int len = s.removeDuplicates(arr, 16);
  for (int i = 0; i < len; i++) {
    cout << arr[i] << ", ";
  }
  cout << endl;
  cout << "Unique length: " <<  len << endl;
  return 0;
}