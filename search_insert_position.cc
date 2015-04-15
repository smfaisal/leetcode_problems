#include <iostream>

using namespace std;

class Solution {
public:
  int binSearch(int A[], int st, int end, int target) {
    if (st > end) {
      return st;
    }
    int mid = (st+end)/2;
    if (A[mid] == target) {
      return mid;
    } else if (A[mid] < target) {
      return binSearch(A, mid+1, end, target);
    } else {
      return binSearch(A, st, mid-1, target);
    }
  }

  int searchInsert(int A[], int n, int target) {
    if (n == 0) {
      return 0;
    }

    return binSearch(A, 0, n-1, target);
  }
};

int main() {
  Solution s;
  int A[] = {2, 3, 5, 8, 9};
  int res = s.searchInsert(A, 5, 1);
  cout << "Res: " << res << endl;
  return 0;
}