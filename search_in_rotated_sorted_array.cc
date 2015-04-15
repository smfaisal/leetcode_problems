#include <iostream>

using namespace std;

class Solution {
public:

  int binSearch(int A[], int st, int end, int target) {
    if (st > end) {
      return -1;
    }
    int mid = (st+end)/2;
    if (A[mid] == target) {
      return mid;
    } else if(target > A[mid]) {
      if (A[st] < A[mid]) {
        return binSearch(A, mid+1, end, target);
      } else {
        if (A[end] >= target) {
          return binSearch(A, mid+1, end, target);
        } else {
          return binSearch(A, st, mid-1, target);
        }
      }
    } else {
      if (A[end] < A[mid]) {
        if (A[end] >= target) {
          return binSearch(A, mid+1, end, target);
        } else {
          if (A[st] <= target) {
            return binSearch(A, st, mid-1, target);
          } else {
            return -1;
          }
        }
      } else {
        return binSearch(A, st, mid-1, target);
      }
    }
  }
  int search(int A[], int n, int target) {
    if (n == 0) {
      return -1;
    } else if (n == 1) {
      if (A[0] == target) {
        return 0;
      } else {
        return -1;
      }
    } else {
      return binSearch(A, 0, n-1, target);
    }
  }
};

int main() {
  Solution s;
  int A[8] = {5,1,2,3,4};
  int res = s.search(A, 5, 1);
  cout << "Res: " << res << endl;
  return 0;
}