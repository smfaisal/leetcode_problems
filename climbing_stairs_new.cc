#include <iostream>

using namespace std;

class Solution {
public:
 int climbStairs(int n) {
   if (n < 2) {
     return n;
   }

   int* ways = (int* )malloc(sizeof(int)*n);
   ways[0] = 1;
   ways[1] = 2;

   for (int i = 2; i < n; i++) {
     ways[i] = ways[i-1] + ways[i-2];
   }
   return ways[n-1];
 }
};

int main() {
  Solution s;
  int ways = s.climbStairs(38);
  cout << "Ways: " << ways << endl;
  return 0;
}