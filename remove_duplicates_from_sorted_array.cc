#include <iostream>

using namespace std;

class Solution {
public:
  int removeDuplicates(int A[], int n) {
    if (n < 2) {
      return n;
    }
    int next = 0;
    for (int i = 1; i < n; i++) {
      if (A[i] != A[i-1]) {
        next++;
        if (i != next) {
          A[next] = A[i];
        }
      }
    }
    return next+1;
  }
};

int main() {
  Solution s;
  int arr[] = {1, 1, 2, 3, 3, 3, 4, 5, 5, 5, 5, 5, 5, 10, 10, 10};

  cout << "Unique length: " << s.removeDuplicates(arr, 16) << endl;
  return 0;
}