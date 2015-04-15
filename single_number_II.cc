#include <iostream>

/**
 * Explanation: http://blog.csdn.net/jinyonghorse/article/details/12906603
 */

using namespace std;

class Solution {
public:
  int singleNumber(int A[], int n) {
    int ones = 0;
    int twos = 0;

    for (int i = 0; i < n; i++) {
      twos |= ones & A[i];
      ones ^= A[i];

      int third = ~(ones & twos);
      ones &= third;
      twos &= third;
    }
    return ones;
  }
};