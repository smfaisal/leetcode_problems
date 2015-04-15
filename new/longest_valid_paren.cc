#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

class Solution {
public:
  int longestValidParentheses(string s) {
    if (s.size() < 2) {
      return 0;
    }
    int len = 0;
    int m_len = 0;
    stack<int> stk;

    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '(') {
        stk.push(i);
      } else {
        if (stk.size() == 0) {
          stk.push(i);
        } else if (s[stk.top()] == ')') {
          stk.pop();
          stk.push(i);
        } else {
          stk.pop();
          if (stk.size() == 0) {
            len = i+1;
          } else {
            len = i-stk.top();
          }
          cout << "len: " << len << " m_len: " << m_len << endl;
          if (m_len < len) {
            m_len = len;
          }
        }
      }
    }
    return m_len;
  }
};

int main() {
  Solution s;
  string str = "(()))())(";//")()())()()(";
  cout << "Len: " << s.longestValidParentheses(str) << endl;
  return 0;
}