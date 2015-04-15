#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    if (s1.size() == 0) {
      return (s2 == s3);
    } else if (s2.size() == 0) {
      return (s1 == s3);
    } else if (s1.size() + s2.size() != s3.size()) {
      return false;
    }

    vector<vector<bool> > A(s1.size()+1, vector<bool>(s2.size()+1, false));

    A[0][0] = true;
    for (int i = 1; i <= s1.size(); i++) {
      if (s3[i-1] == s1[i-1] && A[i-1][0]) {
        A[i][0] = true;
      }
    }
    for (int i = 1; i <= s2.size(); i++) {
      if (s3[i-1] == s2[i-1] && A[0][i-1]) {
        A[0][i] = true;
      }
    }

    for (int i = 1; i <= s1.size(); i++) {
      for (int j = 1; j <= s2.size(); j++) {
        if (s3[i+j-1] == s1[i-1]) {
          A[i][j] = A[i][j] || A[i-1][j];
        }
        if(s3[i+j-1] == s2[j-1]) {
          A[i][j] = A[i][j] || A[i][j-1];
        }
      }
    }
    return A[s1.size()][s2.size()];
  }
};

int main() {
  Solution s;
  cout << "Interleaved?: " << s.isInterleave("aabc", "abad", "aabadabc") << endl;

  return 0;
}