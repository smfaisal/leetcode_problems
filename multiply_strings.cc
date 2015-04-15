#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>

using namespace std;

class Solution{
public:
  string itos(int i) {
    stringstream ss;
    ss << i;
    return ss.str();
  }

  string ultos(unsigned long i) {
    stringstream ss;
    ss << i;
    return ss.str();
  }

  long stol(string s) {
    stringstream ss(s);
    long l;
    ss >> l;
    return l;
  }
  string multiply(string s1, string s2) {
    int l1 = s1.size();
    int l2 = s2.size();
    string res;
    unsigned long grand_res = 0;
    int n1, n2;
    int base = 1;
    reverse(s1.begin(), s1.end());
    n1 = stol(s1);
    int mult, carry = 0;
    for (int i = 0; i < l2; i++) {
      n2 = s2[i]-'0';
      mult = n1*n2*base;
      grand_res += mult;
      base*=10;
    }
    return ultos(grand_res);
  }
};

int main() {
  Solution s;
  string res = s.multiply("21", "01");

  cout << "Res: " << res << endl;
}