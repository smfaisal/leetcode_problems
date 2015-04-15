#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <cmath>

using namespace std;

class Solution {
public:
  static string itos(int n) {
    stringstream ss;
    ss << n;
    return ss.str();
  }

  struct mycomp{
    bool operator()(int a, int b) {
      string num1 = itos(a)+itos(b);
      string num2 = itos(b)+itos(a);

      return (stoll(num1)>stoll(num2));
    }
  } comp;

  string largestNumber(vector<int> &num) {
    string res;

    if (num.size() == 0) {
      return res;
    }
    sort(num.begin(), num.end(), comp);
    int i = 0;
    while (i < num.size() && num[i] == 0) {
      i++;
    }
    if (i == num.size()) {
      res += "0";
    } else {
      for (; i < num.size(); i++) {
        res+=itos(num[i]);
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  int a[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
  vector<int> num(a, a+100);
  string res = s.largestNumber(num);
  cout << "Largest: " << res << endl;
  return 0;
}