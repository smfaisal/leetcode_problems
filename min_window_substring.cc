#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
  bool contains(string s1, string s2) {
    size_t ind;
    for (int i = 0; i < s2.length(); i++) {
      ind = s1.find(s2[i]);
      if (ind == string::npos) {
        return false;
      } else {
        s1[ind] = '~';
      }
    }
    return true;
  }

  string minWindow(string S, string T) {
    string res = "";
    for (int i = T.length(); i <= S.length(); i++) {
      for (int x = 0; x <= S.length()-i; x++) {
        res = S.substr(x, i);
        if (contains(res, T)) {
          return res;
        }
      }
    }
    return "";
  }
};

int main() {
  Solution s;
  string s1("A");//DOBECODEBANC");
  string s2("A");//BC");

  string res = s.minWindow(s1, s2);

  cout << "Res: " << res << endl;
  return 0;
}