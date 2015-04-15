#include <iostream>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

class Solution {
public:
  int toInt(string str) {
    int res = 0;
    int sz = str.size();
    for (int i = 0; i < sz; i++) {
      if (str[i] == '1') {
        res+= (int)pow(2, (sz-1-i));
      }
    }
    return res;
  }

  void getCode(int n, vector<string>& str_res) {
    if (n == 1) {
      str_res.push_back("0");
      str_res.push_back("1");
      return;
    } else {
      vector<string> tmp;
      getCode(n-1, tmp);
      for (int i = 0; i < tmp.size(); i++) {
        str_res.push_back("0"+tmp[i]);
      }
      for (int i = tmp.size()-1; i >= 0; i--) {
        str_res.push_back("1"+tmp[i]);
      }
      tmp.clear();
      return;
    }
  }

  vector<int> grayCode(int n) {
    vector<int> result(1,0);
    if (n == 0) {
      return result;
    }
    vector<string> str_res;
    getCode(n, str_res);

    for (int i = 1; i < str_res.size(); i++) {
      cout << str_res[i] << endl;
      result.push_back(toInt(str_res[i]));
    }
    return result;
  }
};

int main() {
  Solution s;
  vector<int> res;

  res = s.grayCode(0);
  cout << "Gray Code: " << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << endl;
  }
  cout << endl;
  return 0;
}
