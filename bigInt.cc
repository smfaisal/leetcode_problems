#include <iostream>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

class BigInt {
public:
  BigInt(string str):number(str) {}
  BigInt add(const BigInt& b) const;
  string addStrings(string a, string b) const;
  string itos(int i) const {
    stringstream ss;
    ss << i;
    return ss.str();
  }
  string getNumber() const {return number;}
private:
  string number;
};


string BigInt::addStrings(string a, string b) const {
  int a_len = a.size();
  int b_len = b.size();

  int l = min(a_len, b_len);
  string r;
  int sum, carry = 0;
  for (int i = 0; i < l; i++) {
    sum = carry + (a[a_len-1-i]-'0') + (b[b_len-1-i]-'0');
    //cout << sum << endl;
    carry = sum/10;
    sum = sum%10;
    r += itos(sum);
  }
  if (a_len > l) {
    for (int i = a_len-l-1; i >= 0; i--) {
      sum = carry + (a[i]-'0');
      carry = sum/10;
      sum = sum%10;
      r+= itos(sum);
    }
  } else {
    for (int i = b_len-l-1; i >= 0; i--) {
      sum = carry + (b[i]-'0');
      carry = sum/10;
      sum = sum%10;
      r+= itos(sum);
    }
  }

  reverse(r.begin(), r.end());
  return r;
}

BigInt BigInt::add(const BigInt& b) const {
  BigInt res(addStrings(number, b.getNumber()));
  return res;
}

int main() {
  BigInt a("120");
  BigInt b("0");
  BigInt c = a.add(b);

  cout << "Sum of " << a.getNumber() << " and " << b.getNumber() << " is: " << c.getNumber() << endl;
  return 0;
}