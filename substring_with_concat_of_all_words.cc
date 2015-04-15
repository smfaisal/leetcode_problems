#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  vector<int> findSubstring(string S, vector<string> &L) {
    vector<int> result;
    unordered_map<string, int> dict;
    bool is_found;

    if (L.size() == 0 || S.size() < L.size()*L[0].size()) {
      return result;
    }
    for (vector<string>::iterator it = L.begin(); it != L.end(); ++it) {
      dict[*it]++;
    }
    int target_len = L.size()*L[0].size();
    for (int i = 0; i <= S.size()-target_len; i++) {
      unordered_map<string, int> mp;
      int j = 0;
      while (j < L.size()) {
        string sub = S.substr(i+j*L[0].size(), L[0].size());
        if (dict.find(sub) == dict.end()) {
          break;
        }
        mp[sub]++;
        if (mp[sub] > dict[sub]) {
          break;
        }
        j++;
      }
      if (j == L.size()) {
        result.push_back(i);
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  vector<int> result;
  string str("aaa"); //"abcfoobarfooabcbarfoo");
  string l[] = {"a", "a"}; //{"foo", "bar"};
  vector<string> list(l, l+2);

  result = s.findSubstring(str, list);

  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << ", ";
  }
  cout << endl;
  return 0;
}