#include <iostream>
#include <sstream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

class Solution {
 public:
  int strToInt(string s) {
    int val;
    istringstream buffer(s);
    buffer >> val;
    return val;
  }

  void getPair(stack<int>& numbers, int& num1, int& num2) {
    num2 = numbers.top();
    numbers.pop();
    num1 = numbers.top();
    numbers.pop();
  }

  int evalRPN(vector<string> &tokens) {
    int val = 0;
    int num1, num2;
    stack<int> numbers;
    for (int i = 0; i < tokens.size(); i++) {
      if (tokens[i] == "+") {
          getPair(numbers, num1, num2);
          val = num1 + num2;
          numbers.push(val);
      } else if (tokens[i] == "-") {
          getPair(numbers, num1, num2);
          val = num1 - num2;
          numbers.push(val);
      } else if (tokens[i] == "*") {
          getPair(numbers, num1, num2);
          val = num1 * num2;
          numbers.push(val);
      } else if (tokens[i] == "/") {
          getPair(numbers, num1, num2);
          val = num1 / num2;
          numbers.push(val);
      } else {
          numbers.push(strToInt(tokens[i]));
      }
    }
    return numbers.top();
  }
};

int main() {
  Solution s;
  vector<string> tokens;
  tokens.push_back("4");
  tokens.push_back("13");
  tokens.push_back("5");
  tokens.push_back("/");
  tokens.push_back("+");

  int res = s.evalRPN(tokens);

  cout << "Res: " << res << endl;
}
