#include <iostream>
#include <vector>
#include <string>
#include <sstream>


using namespace std;

class Solution {
public:
  void dfs(string s, int st, int dots_left, string cur, vector<string>& res){
    if (st >= s.size()) {
      return;
    } else if (dots_left == 0) {
      int n = stoi(s.substr(st));
      if (n >= 0 && n < 256) {
        if (st < s.size()-1 && s[st] == '0') {
          return;
        }
        cur += s.substr(st);
        //cout << cur << endl;
        res.push_back(cur);
      }
      return;
    } else {
      dfs(s, st+1, dots_left-1, cur+s[st]+".", res);
      for (int i = 2; i <= 3 && s[st] != '0'; i++) {
        int tmp = stoi(s.substr(st, i));
        if (tmp >= 0 && tmp < 256) {
          //cur+=s.substr(st,i) + ".";
          dfs(s, st+i, dots_left-1, cur+s.substr(st,i)+".", res);
        }

      }
    }
  }

  vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    if (s.size() < 4 || s.size() > 12) {
      return res;
    }
    string cur = "";
    dfs(s, 0, 3, cur, res);
    return res;
  }
};

int main() {
  Solution s;
  vector<string> res;
  res = s.restoreIpAddresses("0000");
  cout << "Res: " << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << endl;
  }
  return 0;
}