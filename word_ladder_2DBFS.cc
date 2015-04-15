#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>
#include <algorithm>
#include <queue>

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
  bool hasCommon(unordered_set<string>& f_q, unordered_set<string>& b_q) {
    unordered_set<string>::iterator it = f_q.begin();
    for (; it != f_q.end(); it++) {
      if (b_q.find(*it) != b_q.end()) {
        return true;
      }
    }
    return false;
  }

  int ladderLength(string start, string end, unordered_set<string> &dict) {
    if (start == end) {
      return 0;
    } else if (dist(start, end) == 1) {
      return 1;
    }
    unordered_set<string> used_front;
    unordered_set<string> used_back;
    queue<string> f_bfs_q;
    queue<string> b_bfs_q;
    unordered_set<string> fq_cont;
    unordered_set<string> bq_cont;
    f_bfs_q.push(start);
    b_bfs_q.push(end);
    int f_cur_len = 0;
    int b_cur_len = 0;
    string item;
    while (f_bfs_q.size() > 0) {
      item = f_bfs_q.front();
      f_bfs_q.pop();
      string s;
      for (int i = 0; i < item.size(); i++) {
        s = item;
        for (char ch = 'a'; ch <= 'z'; ch++) {
          s[i] = ch;
          if (dict.find(s) != dict.end()) {
            f_bfs_q.push(s);
            fq_cont.insert(s);
          }
        }
      }
      f_cur_len++;
      item = b_bfs_q.front();
      b_bfs_q.pop();

      for (int i = 0; i < item.size(); i++) {
        s = item;
        for (char ch = 'a'; ch <= 'z'; ch++) {
          s[i] = ch;
          if (dict.find(s) != dict.end()) {
            b_bfs_q.push(s);
            bq_cont.insert(s);
          }
        }
      }
      b_cur_len++;
      if (hasCommon(fq_cont, bq_cont)) {
        return f_cur_len+b_cur_len;
      }
    }
    return 0;
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