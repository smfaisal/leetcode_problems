#include <iostream>

using namespace std;

class Solution {
public:
  int maxSubArray(int A[], int n) {
    int max = INT_MIN;
    int sum = INT_MIN;
    for (int i = 0; i < n; i++) {
      sum = (sum > 0)?sum+A[i]:A[i];
      if (sum > max) {
        max = sum;
      }
    }

    return max;
  }
};

int main() {
  Solution s;
  int a[] = {-2,1,-3,4,-1,2,1,-5,4};
  cout << "Max sum is: " << s.maxSubArray(a, 9) << endl;
  return 0;
}