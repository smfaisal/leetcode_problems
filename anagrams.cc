#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  vector<string> anagrams(vector<string> &strs) {
    vector<string> res;

    if (strs.size() == 0) {
      return res;
    }

    unordered_map<string, int> mp;
    string t;
    for (int i = 0; i < strs.size(); i++) {
      t = strs[i];
      sort(t.begin(), t.end());
      mp[t]++;
    }

    for (int i = 0; i < strs.size(); i++) {
      t = strs[i];
      sort(t.begin(), t.end());
      if (mp[t] >= 2) {
        res.push_back(strs[i]);
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<string> strs;
  strs.push_back("abcd");
  strs.push_back("bcad");
  strs.push_back("cdab");
  strs.push_back("aksd");
  strs.push_back("sld");
  strs.push_back("dcba");

  vector<string> res = s.anagrams(strs);

  for (int i = 0; i < res.size(); i++) {
    cout << res[i] << endl;
  }
  return 0;
}