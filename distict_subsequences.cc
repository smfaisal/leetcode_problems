#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
  void dfs(string& T, int ind, int last, unordered_map<char, vector<int> >&cm, int& tot) {
    if (ind >= T.size()) {
      tot++;
      return;
    }
    for (int i = 0; i < cm[T[ind]].size(); i++) {
//      cout << "ind: " << ind << " last: " << last << " c: " << cm[T[ind]][i] << endl;
      if (cm[T[ind]][i] > last) {
        dfs(T, ind+1, cm[T[ind]][i], cm, tot);
      }
    }
  }

  int numDistinct(string S, string T) {
    if (S.size() == 0) {
      return 0;
    }
    if (T.size() == 0) {
      return 1;
    }
    unordered_map<char, vector<int> > cm;
    for (int i = 0; i < T.size(); i++) {
      if (cm.find(T[i]) != cm.end()) {
        continue;
      }
      for (int j = 0; j < S.size(); j++) {
        if (T[i] == S[j]) {
//          if (cm.find(T[i]) == cm.end()) {
//          cout << T[i] << ": " << j << endl;
          cm[T[i]].push_back(j);
//          }
        }
      }
    }
    int tot = 0;
    dfs(T, 0, -1, cm, tot);
    return tot;
  }
};

int main() {
  Solution s;
  string S = "rabbbit";
  string T = "rabbit";

  int tot = s.numDistinct(S, T);
  cout << "Distinct: " << tot << endl;
  return 0;
}