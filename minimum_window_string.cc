#include <iostream>
#include <string>
#include <deque>
#include <unordered_map>

using namespace std;

class Solution {
public:
  string minWindow(string S, string T) {
    if (S.size() == 0 ||
        S.size() < T.size()) {
      return "";
    }
    unordered_map<char, int> to_be_found;
    unordered_map<char, int> found;

    for (int i = 0; i < T.size(); i++) {
      to_be_found[T[i]]++;
    }

    deque<std::pair<char, int> > dq;
    int t_len = 0;
    int min_len = INT_MAX;
    int cur_len = INT_MAX;
    int min_st = -1;
    for (int i = 0; i < S.size(); i++) {
      if (to_be_found.find(S[i]) != to_be_found.end()) {
        if (T.size() == 1) {
          return S.substr(i, 1);
        }
        if (found.find(S[i]) == found.end()) {
          found[S[i]] = 1;
        } else {
          found[S[i]]++;
        }
        if (found[S[i]] <= to_be_found[S[i]]) {
          t_len++;
        }
        if (t_len == T.size()) {
          while (found[dq.front().first] > to_be_found[dq.front().first]) {
            found[dq.front().first]--;
            dq.pop_front();
          }
          cur_len = i-dq.front().second+1;
          if (cur_len < min_len) {
            min_len = cur_len;
            min_st = dq.front().second;
          }
          // Remove from queue
          found[dq.front().first]--;
          dq.pop_front();
          t_len--;

        }
        dq.push_back(make_pair(S[i], i));
      }
    }
    return (min_st >= 0)?S.substr(min_st, min_len):"";
  }
};

int main() {
  Solution s;
  string S("adobecodebancbbcaa");//("acbbaca");//("ADOBECODEBANC");//
  string T("abc");//("aba");//("ABC");//
  string min = s.minWindow(S, T);
  cout << min << endl;
  return 0;
}