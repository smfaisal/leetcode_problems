#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
  long factorial(int k, long res) {
    if (k == 1) {
      return res;
    }
    res *= k;
    return factorial(k-1, res);
  }

  void permutate(string& perm, int st, int end, int k) {
    if (k == 0) {
      return;
    }
    long fact = factorial(end-st, 1);

    int div = (k)/fact;
    int rem = (k)%fact;

    swap<char>(perm[st], perm[st+div]);
    sort(perm.begin()+st+1, perm.end());
    permutate(perm, st+1, end, rem);
  }

  string getPermutation(int n, int k) {
    string perm = "";
    if (n == 0) {
      return perm;
    }
    char c;
    int i;
    for (c = '1', i = 1; i <= n; c++, i++) {
      perm += c;
    }

    if (k < 2) {
      return perm;
    }

    permutate(perm, 0, n-1, k-1);
    return perm;
  }
};

int main() {
  Solution s;
  int k = 11;
  string perm = s.getPermutation(4, k);
  cout << k << "-th permutation: " << perm << endl;
  return 0;
}