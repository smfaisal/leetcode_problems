#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
  int longestValidParentheses(string s) {
    int num = 0;
    int cur_len = 0;
    int st_ind = 0;
    stack<pair<char, int> > stk;
    pair<char, int> item;
    if (s.size() < 2) {
      return num;
    }
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        stk.push(make_pair(s[i], i));
      } else {
        if (stk.empty()) {
          st_ind = i+1;
        } else {
          item = stk.top();
          stk.pop();
          if (stk.empty()) {
            num = max(num, i-st_ind+1);
          } else {
            num = max(num, i-stk.top().second);
          }
        }
      }
    }

    return num;
  }
};

int main() {
  Solution s;
  string str = "()(()()";
  cout << "Len: " << s.longestValidParentheses(str) << endl;
  return 0;
}