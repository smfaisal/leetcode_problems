#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
  int dist(string s1, string s2) {
    int len = 0;
    for (int i = 0; i < s1.size(); i++) {
      if (s1[i] != s2[i]) {
        len++;
      }
    }
    return len;
  }

  void getLen(int st, int end, vector<string>& all, vector<vector<int> >& d, unordered_set<int>& used, int& cur_len, int& best_len) {
//    cout << "st: " << st << " end: " << end << " cur_len: " << cur_len << " b_len: " << best_len << endl;
    if (d[st][end] == 1) {
      cur_len++;
      if (best_len > cur_len) {
        best_len = cur_len;
      }
      return;
    }

    for (int i = 0; i < all.size(); i++) {
      if (d[st][i] == 1 && used.find(i) == used.end()) {
        cur_len++;
        used.insert(i);
        getLen(i, end, all, d, used, cur_len, best_len);
        used.erase(i);
        cur_len--;
      }
    }
  }

  int ladderLength(string start, string end, unordered_set<string> &dict) {
    if (start == end) {
      return 0;
    }
    vector<string> all;
    all.push_back(start);
    unordered_set<string>::iterator it = dict.begin();
    for (; it != dict.end(); it++) {
      all.push_back(*it);
    }
    all.push_back(end);

    vector<vector<int> > d(all.size(), vector<int>(all.size(), 0));

    for (int i = 0; i < all.size(); i++) {
      for (int j = 0; j < all.size(); j++) {
        d[i][j] = dist(all[i], all[j]);
      }
    }
//    for (int i = 0; i < d.size(); i++) {
//      cout << all[i] << " ";
//    }
//    cout << endl;
//    for (int i = 0; i < d.size(); i++) {
//      for (int j = 0; j < d.size(); j++) {
//        cout << d[i][j] << " ";
//      }
//      cout << endl;
//    }
    unordered_set<int> used;
    used.insert(0);
    int cur_len = 0;
    int best_len = INT_MAX;
    getLen(0, all.size()-1, all, d, used, cur_len, best_len);
    return best_len;
  }
};


int main() {
  Solution s;
  string start = "hit";
  string end = "cog";
  string arr[] = {"hot","dot","dog","lot","log"};
  unordered_set<string> dict(arr, arr+5);

  int len = s.ladderLength(start, end, dict);
  cout << "Len: " << len << endl;
  return 0;
}