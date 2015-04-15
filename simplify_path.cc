#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
public:
  string simplifyPath(string path) {
    string result;
    if (path.size() == 0) {
      return result;
    }
    stack<string> stk;
    int i = 0;
    int slash_ind = -1;
    string part;
    while (i < path.size()) {
      if (path[i] == '/') {
        if (i > slash_ind+1) {
          part = path.substr(slash_ind+1, i-slash_ind-1);
          if (part == ".") {

          } else if (part == "..") {
            if (stk.size() > 0) stk.pop();
          } else {
            stk.push(part);
          }
        }
        slash_ind = i;
      }
      i++;
    }
    if (slash_ind < path.size()-1) {
      part = path.substr(slash_ind+1);
      if (part == ".") {

      } else if (part == "..") {
          if (stk.size() > 0) stk.pop();
      } else {
        stk.push(part);
      }
    }
    if (stk.size() == 0) {
      result = "/";
    } else {
      while (!stk.empty()) {
        result = "/"+stk.top()+result;
        stk.pop();
      }
    }
    return result;
  }
};

int main() {
  Solution s;
  string result = s.simplifyPath("/home/foo/.bashrc");
  cout << "Simplified path: " << result << endl;
  return 0;
}