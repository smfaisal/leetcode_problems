#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
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

  void neighbors(string str, queue<string>& q, unordered_set<string>& done,
                 unordered_set<string>& dict) {
    string s;
    for (int i = 0; i < str.size(); i++) {
      s = str;
      for (char j = 'a'; j <= 'z'; j++) {
        s[i] = j;
        cout << s << ", ";
        if (s == "dog") {
          for (auto it = dict.begin(); it != dict.end(); it++) {
            cout << "dict : " << *it;
          }
          cout << endl;
          for (auto it = done.begin(); it != done.end(); it++) {
            cout << "done : " << *it;
          }
        }
        if (dict.find(s) != dict.end()) {
          cout << "Found: " << s << ", ";
          if (done.find(s) == done.end()) {
            cout << "Pushed: " << s << ", ";
            q.push(s);
            done.insert(s);
          }
        }
      }
    }
  }

  int ladderLength(string start, string end, unordered_set<string> &dict) {
    unordered_set<string> done;
    queue<string> q;
    q.push(start);
    string s1;
    int len = 0;
    while (!q.empty()) {
      s1 = q.front();
      cout << s1 << endl;
      q.pop();
      done.insert(s1);
      len++;
      if (s1 == end) {
        return len;
      } else if (dist(s1, end) == 1) {
        len++;
        return len;
      } else {
        neighbors(s1, q, done, dict);
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