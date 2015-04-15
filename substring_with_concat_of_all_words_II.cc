#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:

  bool isConcat(string s, unordered_map<string, int>& lmap, int wlen) {
    unordered_map<string, int> temp(lmap.begin(), lmap.end());
    for (int i = 0; i < s.length(); i+=wlen) {
      string str = s.substr(i, wlen);
      if (temp.find(str) == temp.end()) {
        return false;
      } else {
        temp[str] -= 1;
      }
    }
    unordered_map<string, int>::iterator it = temp.begin();
    for (; it != temp.end(); it++) {
      if (it->second != 0) {
        return false;
      }
    }
    return true;
  }
  vector<int> findSubstring(string S, vector<string> &L) {
    vector<int> res;
    if (L.size() == 0 || S.length() == 0) {
      return res;
    }
    int wlen = L[0].length();
    int len = L.size() * wlen;
    if (S.length() < len) {
      return res;
    }
    unordered_map<string, int> L_map;
    for (int i = 0; i < L.size(); i++) {
      L_map[L[i]]++;
    }

    for (int i = 0; i <= S.length()-len; i+= 1) {
      //string str = S.substr(i, len);
      unordered_map<string, int> mp;
      int j;
      for (j = 0; j < L.size(); j++) {
        string str = S.substr(i+j*wlen, wlen);
        if (L_map.find(str) == L_map.end()) {
          break;
        } else {
          mp[str]++;
          if (mp[str] > L_map[str]) {
            break;
          }
        }
      }
      if (j == L.size()) {
        res.push_back(i);
      }
    }
    return res;
  }
};

int main() {
  Solution s;
  vector<int> result;
  string str("lingmindraboofooowingdingbarrwingmonkeypoundcake");//"aaa"); //"abcfoobarfooabcbarfoo");
  string l[] = {"fooo","barr","wing","ding","wing"};//"a", "a"}; //{"foo", "bar"};
  vector<string> list(l, l+5);

  result = s.findSubstring(str, list);

  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << ", ";
  }
  cout << endl;
  return 0;
}
