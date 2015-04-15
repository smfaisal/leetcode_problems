#include <iostream>
#include <stack>

using namespace std;

class MinStack {
public:
  stack<int> stk;
  stack<int> mstk;

  void push(int x) {
    stk.push(x);
    if (mstk.size() == 0) {
      mstk.push(x);
    } else {
      if (x <= mstk.top()) {
        mstk.push(x);
      }
    }
  }

  void pop() {
    if (stk.top() == mstk.top()) {
      mstk.pop();
    }
    stk.pop();
  }

  int top() {
    return stk.top();
  }

  int getMin() {
    return mstk.top();
  }
};

int main() {
  MinStack mystack;
  mystack.push(5);
  mystack.push(2);
  mystack.push(3);
  mystack.push(4);
  mystack.push(1);

  for (int i = 0; i < 5; i++) {
    cout << "Top: " << mystack.top() << " min: " << mystack.getMin() << endl;
    mystack.pop();
  }
  cout << endl;
  return 0;
}