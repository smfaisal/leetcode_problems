#include <iostream>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
  string convertToTitle(int n) {
    string res;
    if (n == 0) {
      return res;
    }
    int base = 26;
    int rem;
    while (n > 26) {
      rem = (n%base);
      n/= base;
      if (rem == 0) {
        rem = 26;
        n--;
      }
      res += 'A'+rem-1;
    }
    if (n) {
      res += 'A'+n-1;
    }
    reverse(res.begin(), res.end());
    return res;
  }
};

int main() {
  Solution s;
  string str = s.convertToTitle(52);//18307);

  cout << "Title: " << str << endl;
  return 0;
}