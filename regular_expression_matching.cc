#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
  bool match(string s, int s_st, string p, int p_st) {
    if (p_st >= p.size()) {
      if (s_st >= s.size()) {
        return true;
      } else {
        return false;
      }
    }
    if (s_st >= s.size()) {
      return false;
    }
    if (p_st + 1 < p.size()) {
      if (p[p_st+1] == '*') {
        if (p[p_st] == '.') {
          return match(s, s_st, p, p_st+2) || match(s, s_st+1, p, p_st);
        } else {
          if (match(s, s_st, p, p_st+2)) {
            return true;
          }
          if (s[s_st] == p[p_st]) {
            return match(s, s_st+1, p, p_st) || match(s, s_st+1, p, p_st+2);
          }
        }
      }
    }
    if (p[p_st] == '.') {
      return match(s, s_st+1, p, p_st+1);
    } else {
      if (s[s_st] == p[p_st]) {
        return match(s, s_st+1, p, p_st+1);
      } else {
        return false;
      }
    }
  }
  bool isMatch(string s, string p) {
    if (p.size() == 0) {
      return true;
    }
    if (s.size() == 0) {
      return false;
    }
    return match(s, 0, p, 0);
  }
};

int main() {
  Solution s;
  bool m = s.isMatch("aaaaaaaaaaaaab", "a*a*a*a*a*a*a*a*a*a*c");
  cout << "Match?: " << m << endl;
  return 0;
}