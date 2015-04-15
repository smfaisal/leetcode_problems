#include <iostream>

using namespace std;

class Solution {
public:
  bool binSearch(int A[], int st, int end, int target) {
    if (st > end) {
      return false;
    }
    int mid = (st+end)/2;
    if (A[mid] == target) {
      return true;
    }
    if (A[st] < A[mid]) {
			if (target < A[mid] && target >= A[st]) {
				return binSearch(A, st, mid-1, target);
			} else {
				return binSearch(A, mid+1, end, target);
			}
		}
    if (A[st] > A[mid]){
			if (target <= A[mid] || target >= A[st]) {
					return binSearch(A, st, mid-1, target);
			} else {
					return binSearch(A, mid+1, end, target);
			}
		}
    if (A[mid] == A[st]) {
      return binSearch(A, st+1, end, target);
    }
		return false;
	}

  bool search(int A[], int n, int target) {
    if (n == 0) {
      return false;
    } else if (n == 1) {
      if (A[0] == target) {
        return true;
      } else {
        return false;
      }
    } else {
      return binSearch(A, 0, n-1, target);
    }
  }
};

int main() {
  Solution s;
  int A[9] = {3, 1, 1, 1}; //{10, 10, 10, 15, 15, 2, 6, 6, 8};
  bool res = s.search(A, 2, 1);
  cout << "Res: " << res << endl;
  return 0;
}
