#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int binSearch(int A[], int st, int end, int target, int dir) {
    if (st > end) {
      return -1;
    }
    int mid = (st+end)/2;
    if (A[mid] == target) {
      if (dir == 0) {
        if (A[mid-1] == target) {
          return binSearch(A, st, mid-1, target, dir);
        } else {
          return mid;
        }
      } else {
        if (A[mid+1] == target) {
          return binSearch(A, mid+1, end, target, dir);
        } else {
          return mid;
        }
      }
    } else if (A[mid] < target) {
      return binSearch(A, mid+1, end, target, dir);
    } else {
      return binSearch(A, st, mid-1, target, dir);
    }
  }

  vector<int> searchRange(int A[], int n, int target) {
    vector<int> result;
    int left = binSearch(A, 0, n-1, target, 0);
    int right = binSearch(A, left+1, n-1, target, 1);
    if (left == -1 && right != -1) {
      left = right;
    } else if (left != -1 && right == -1) {
      right = left;
    }
    result.push_back(left);
    result.push_back(right);
    return result;
  }
};

int main() {
  Solution s;
  int a[] = {2, 7, 7, 7, 7, 7, 9};
  vector<int> res = s.searchRange(a, 7, 9);

  cout << "Res: " << res[0] << ", " << res[1] << endl;
  return 0;
}