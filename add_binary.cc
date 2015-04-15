#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  void add(char a, char b, char c, string& res, string& carry) {
    if (a == '0' && b == '0' && c == '0') {
      res = "0"+res;
      carry = "0";
    } else if (a == '0' && b == '0' && c == '1') {
      res = "1"+res;;
      carry = "0";
    } else if (a == '0' && b == '1' && c == '0') {
      res = "1"+res;;
      carry = "0";
    } else if (a == '0' && b == '1' && c == '1') {
      res = "0"+res;
      carry = "1";
    } else if (a == '1' && b == '0' && c == '0') {
      res = "1"+res;;
      carry = "0";
    } else if (a == '1' && b == '0' && c == '1') {
      res = "0"+res;
      carry = "1";
    } else if (a == '1' && b == '1' && c == '0') {
      res = "0"+res;
      carry = "1";
    } else if (a == '1' && b == '1' && c == '1') {
      res = "1"+res;;
      carry = "1";
    }
  }

  string addBinary(string a, string b) {
    string res;
    if (a.size() == 0 && b.size() == 0) {
      return res;
    }
    int a_len = a.size()-1;
    int b_len = b.size()-1;
    char r = '0';
    string carry = "0";

    while (a_len >= 0 && b_len >= 0) {
      add(a[a_len--], b[b_len--], carry[0], res, carry);
    }
    if (a_len < 0) {
      while (b_len >= 0) {
        add('0', b[b_len--], carry[0], res, carry);
      }
    } else if (b_len < 0) {
      while (a_len >= 0) {
        add(a[a_len--], '0', carry[0], res, carry);
      }
    }
    if (carry == "1")
      res = carry+res;
    return res;
  }
};

int main() {
  Solution s;
  string res = s.addBinary("11", "1");
  cout << "Res: " << res << endl;
  return 0;
}