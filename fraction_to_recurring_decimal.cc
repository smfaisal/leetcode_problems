#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <cstdlib>

using namespace std;

class Solution {
public:
  string itos(long long i) {
    stringstream ss;
    ss << i;
    return ss.str();
  }
  string fractionToDecimal(int numerator, int denominator) {
    string res;
    if (numerator == 0 || denominator == 0) {
      return "0";
    }

    if ((numerator < 0 && denominator > 0) ||
        (numerator > 0 && denominator < 0)) {
        res += "-";
    }

//    cout << "num: " << numerator << " denom: " << denominator << endl;

    long long num = labs(numerator);
    long long denom = labs(denominator);
    cout << "num: " << num << " denom: " << denom << " res: " << res  << endl;
    if (num < denom) {
      res += "0";
    }
    else {
      while (num/denom > 0) {
        res += itos(num/denom);
        cout << itos(num/denom) << endl;
        num = num%denom;
      }
    }
    if (num > 0) {
      res += ".";
    } else {
      return res;
    }
    unordered_map<int, int> mp;
    while (num && mp.find(num) == mp.end()) {
//      cout << num << ", " << denom << endl;
      mp[num] = res.size();
      num*=10;
      res += itos(num/denom);
      num = num%denom;
    }
    if (num) {
      res.insert(mp[num], "(");
      res += ")";
    }
    return res;
  }
};

int main() {
  Solution s;
  string res = s.fractionToDecimal(-2147483648, 1);
  cout << "Res: " << res << endl;
  return 0;
}