#include <iostream>
#include <string>

using namespace std;

class Solution{
public:
  void dfs(string s1, int s1_st, string s2, int s2_st, int& match) {
    if (s1_st >= s1.size()) {
      cout << "s1_st: " << s1_st << " s2_st: " << s2_st << endl;
      match++;
      return;
    } else if (s2_st >= s2.size()) {
      return;
    }
      for (int j = s2_st; j < s2.size(); j++) {
        if (s2[j] == s1[s1_st]) {
          dfs(s1, s1_st+1, s2, j+1, match);
        }
      }
  }


  int discontinuousMatch(string s1, string s2){
    if (s1.size() == 0 || s2.size() == 0) {
      return 0;
    }
    int match = 0;
    dfs(s1, 0, s2, 0, match);
    return match;
  }
};

int main() {
  Solution s;
  int match = s.discontinuousMatch("cat", "catapultcat");
  cout << "Match: " << match << endl;
  return 0;
}