#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  bool isPalindrome(string str) {
    int i = 0;
    int j = str.size()-1;
    while (i < j) {
      if (str[i++] != str[j--]) {
        return false;
      }
    }
    return true;
  }
  vector<vector<string> > partition(string s) {
    vector<vector<string> > result;
    if (s.size() == 0) {
      return result;
    }
    int i;
    vector<string> rvec;

    bool discard = false;
    for (i = 1; i <= s.size(); i++) {
      rvec.clear();
      discard = false;
      for (int j = 0; j <= s.size()-i; j++) {
        if (isPalindrome(s.substr(j, i))) {
          rvec.push_back(s.substr(j, i));
          if (j+i < s.size() && isPalindrome(s.substr(j+i))) {
            vector<string> nvec(rvec.begin(), rvec.end());
            nvec.push_back(s.substr(j+i));
            result.push_back(nvec);
          }
        } else {
          discard = true;
          break;
        }
      }
      if (!discard) {
        result.push_back(rvec);
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  cout << "abccba palindrome? : " << s.isPalindrome("abccba") << endl;
  vector<vector<string> > res = s.partition("cdd");
  for (int v = 0; v < res.size(); v++) {
    for (int s = 0; s != res[v].size(); s++) {
      cout << res[v][s] << ", ";
    }
    cout << endl;
  }
  return 0;
}