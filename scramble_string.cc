#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
  unordered_set<string> get(string s1) {
    unordered_set<string> sc;
    if (s1.size() == 1) {
      sc.insert(s1);
      return sc;
    }
    unordered_set<string> tmp1, tmp2;
    for (int i = 1; i < s1.size(); i++) {
//      cout << s1.substr(0, i) << " and " << s1.substr(i) << endl;
      tmp1 = get(s1.substr(0, i));
      tmp2 = get(s1.substr(i));
      for (auto it1 = tmp1.begin(); it1 != tmp1.end(); it1++) {
        for (auto it2 = tmp2.begin(); it2 != tmp2.end(); it2++) {
//          cout << *it1 << " + " << *it2 << endl;
          sc.insert(*it1+*it2);
          sc.insert(*it2+*it1);
        }
      }
    }
    return sc;
  }
  bool isScramble(string s1, string s2) {
    if (s1.size() < 2) {
      return s1==s2;
    }
    unordered_set<string> scrambled;
    scrambled = get(s1);
//    for (auto it = scrambled.begin(); it != scrambled.end(); it++) {
//      cout << *it << endl;
//    }
    if (scrambled.find(s2) != scrambled.end()) {
      return true;
    } else {
      return false;
    }
  }
};

int main() {
  Solution s;
  cout << "Scramble?: " << s.isScramble("great", "rgeat") << endl;
  return 0;
}