#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    if (s3.size() == 0) {
      return true;
    }
    else if (s1.size() + s2.size() != s3.size()) {
      return false;
    }

    vector<vector<bool> > mp(s1.size()+1, vector<bool>(s2.size()+1, false));

    mp[0][0] = true;
    for (int i = 1; i <= s1.size(); i++) {
      if (s3[i-1] == s1[i-1]) {
        mp[i][0] = mp[i-1][0];
      }
    }

    for (int i = 1; i <= s2.size(); i++) {
      if (s3[i-1] == s2[i-1]) {
        mp[0][i] = mp[0][i-1];
      }
    }

    for (int i = 1; i <= s1.size(); i++) {
      for (int j = 1; j <= s2.size(); j++) {
        if (s3[i+j-1] == s1[i-1]) {
          mp[i][j] = mp[i-1][j];
        }
        if (s3[i+j-1] == s2[j-1]) {
          mp[i][j] = (mp[i][j] || mp[i][j-1]);
        }
      }
    }

//    cout << endl;
//    for (int i = 0; i <= s1.size(); i++) {
//      for (int j = 0; j <= s2.size(); j++) {
//        cout << mp[i][j] << " ";
//      }
//      cout << endl;
//
//    }

    return mp[s1.size()][s2.size()];
  }
};


int main() {
  Solution s;
  cout << "Interleaved?: " << s.isInterleave("aabc", "abad", "aabadabc") << endl;

  return 0;
}