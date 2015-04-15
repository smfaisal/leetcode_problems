#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  bool wordBreak(string s, unordered_set<string> &dict) {
    if (s.size() == 0) {
      return true;
    } else if (dict.size() == 0) {
      return false;
    }

    vector<vector<bool> > A(s.size(), vector<bool>(s.size(), false));

    int i, j;
    string str;
    for (i = 0; i < s.size(); i++) {
      for (j = i; j < s.size(); j++) {
        str = s.substr(i, j-i+1);
        if (dict.find(str) != dict.end()) {
//          cout << i << ", " << j << endl;
          A[i][j] = true;
        }
      }
    }

    for (int i = 0; i < s.size(); i++) {
      for (int j = 1; j < s.size()-i; j++) {
        for (int k = i; k < i+j; k++) {
//          cout << i << ", " << j << ", " << k << ": " << A[i][k] << ", " << A[k+1][j] << endl;
          A[i][j] = A[i][j] || (A[i][k] && A[k+1][j]);
        }
      }
    }
    return A[0][s.size()-1];
  }
};

int main() {
  Solution s;
  unordered_set<string> dict;
  dict.insert("cats");
  dict.insert("and");
  dict.insert("dogs");
  dict.insert("a");
  dict.insert("b");


  cout << "Word Break?: " << s.wordBreak("ab", dict) << endl;

  return 0;
}
