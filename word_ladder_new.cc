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

  void getLen(string st, string end, unordered_set<string>& dict, unordered_set<string>& used, int& cur_len, int& best_len) {
//    cout << "st: " << st << " end: " << end << " cur_len: " << cur_len << " b_len: " << best_len << endl;
    if (dist(st, end) == 1) {
      cur_len++;
      if (best_len > cur_len) {
        best_len = cur_len;
      }
      return;
    }
    unordered_set<string>::iterator it = dict.begin();
    for (; it != dict.end(); it++) {
      if (dist(st, *it) == 1 && used.find(*it) == used.end()) {
        cur_len++;
        used.insert(*it);
        getLen(*it, end, dict, used, cur_len, best_len);
        used.erase(*it);
        cur_len--;
      }
    }
  }

  int ladderLength(string start, string end, unordered_set<string> &dict) {
    if (start == end) {
      return 0;
    } else if (dist(start, end) == 1) {
      return 1;
    }
    unordered_set<string> used;
    used.insert(start);
    int cur_len = 0;
    int best_len = INT_MAX;
    getLen(start, end, dict, used, cur_len, best_len);
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