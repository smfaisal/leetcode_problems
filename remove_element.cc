#include <iostream>

using namespace std;

class Solution {
public:
  int removeElement(int A[], int n, int elem) {
    int ind = 0;
    int right = n-1;

    while (ind <= right) {
      if (A[ind] == elem) {
        while (A[right] == elem) {
          right--;
        }
        if (ind < right) {
          A[ind] = A[right];
          right--;
        } else {
          break;
        }
      }
      ind++;
    }
    return right+1;
  }
};

int main() {
  Solution s;
  //int arr[] = {1, 1, 2, 3, 3, 3, 4, 5, 5, 5, 5, 5, 5, 10, 10, 10};
  int arr[] = {1, 1};
  cout << "Unique length: " << s.removeElement(arr, 2, 1) << endl;

  for (int i = 0; i < 16; i++) {
    cout << arr[i] << ", ";
  }
  cout << endl;
  return 0;
}