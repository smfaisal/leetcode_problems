#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
  long strToInt(string str) {
    long res;
    istringstream convert(str);
    if (!(convert >> res)) {
      res = 0;
    }
    // cout << "str: " << str << " Num: " << res << endl;
    return res;
  }

  void dfs(string s, int st, int budget, vector<int>& bp,
           vector<string>& result, vector<vector<bool> >& table) {
    if (st >= s.size()) {
      if (bp.size() == 4) {
        string res = s;
        for (int i = 0; i < bp.size()-1; i++) {
          res.insert(bp[i]+i, ".");
        }
        result.push_back(res);
      }
    } else {
      for (int j = 0; j < table[st].size(); j++) {
        if (table[st][j]) {
          bp.push_back(j+1);
          if (budget >= 0)
            dfs(s, j+1, budget-1, bp, result, table);
          bp.pop_back();
        }
      }
    }
  }

  vector<string> restoreIpAddresses(string s) {
    vector<string> res;
    if (s.size() < 4 || s.size() > 12) {
      return res;
    }
    vector<vector<bool> > table(s.length(), vector<bool>(s.length(), false));
    string tmp;
    long num;
    for (int i = 0; i < s.length(); i++) {
      for (int j = i; j < s.length(); j++) {
        tmp = s.substr(i, j-i+1);
        num = strToInt(tmp);
        // cout << "Num: " << num << endl;
        if (num >= 0 && num <= 255) {
          table[i][j] = true;
        }
      }
    }

    vector<int> bp;
    dfs(s, 0, 3, bp, res, table);
    return res;
  }
};

int main() {
	Solution s;

	string str = "25525511135";
	vector<string> res = s.restoreIpAddresses(str);

	for (int i = 0; i < res.size(); i++) {
		cout << res[i] << "\n";
	}
}