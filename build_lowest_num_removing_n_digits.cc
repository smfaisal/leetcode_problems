#include <iostream>
#include <string>

using namespace std;

class Solution{
public:

  int remSmallest(string t, int st, int end) {
    if (t.size() == 0) {
      return -1;
    }
    int min = t[st]-'0';
    int min_ind = st;
    for (int i = st+1; i <= end; i++) {
      if (t[i]-'0' < min) {
        min = t[i]-'0';
        min_ind = i;
      }
    }
    return min_ind;
  }

  void rem(string num, int st, int n, string& res) {
//    cout << "num: " << num << " st: " << st << " n: " << n << " res: " << res << endl;
    if (n == 0) {
      res+= num.substr(st);
      return;
    }
    if (num.size() == 0 || num.size()-st <= n) {
      return;
    }
    int min_ind = remSmallest(num, st, st+n);
    if (min_ind >= st) {
      res+=num[min_ind];
      rem(num, min_ind+1, n-(min_ind-st), res);
    } else {
      return;
    }

  }

  string removeDigits(string num, int n) {
    string res;
    rem(num, 0, n, res);
    return res;
  }
};

int main() {
  Solution s;
  string number("765028321");
  string res = s.removeDigits(number, 5);
  cout << "Smallest: " << res << endl;
}