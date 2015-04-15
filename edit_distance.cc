#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int minDistance(string word1, string word2) {
    if (word1.size() == 0) {
      return word2.size();
    }
    if (word2.size() == 0) {
      return word1.size();
    }

    vector<vector<int> > edit_distance(word1.size()+1, vector<int>(word2.size()+1, 0));

    for (int i = 0; i <= word2.size(); i++) {
      edit_distance[0][i] = i;
    }
    for (int i = 0; i <= word1.size(); i++) {
      edit_distance[i][0] = i;
    }
    int dist;
    for (int i = 1; i <= word1.size(); i++) {
      for (int j = 1; j <= word2.size(); j++) {
        if (word1[i-1] == word2[j-1]) {
          edit_distance[i][j] = edit_distance[i-1][j-1];
        } else {
          dist = min(edit_distance[i][j-1], edit_distance[i-1][j]);
          dist = min(dist, edit_distance[i-1][j-1]);
          edit_distance[i][j] = dist+1;
        }
        cout << "ed(" << i << j << "): " << edit_distance[i][j] << endl;
      }
    }
    return edit_distance[word1.size()][word2.size()];
  }
};

int main() {
  Solution s;
  string s1 = "distance";
  string s2 = "springbok";

  int dist = s.minDistance(s1, s2);

  cout << "edit distance between " << s1 << " and " << s2 << ": " << dist << endl;

  return 0;
}