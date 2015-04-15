#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int rob(vector<int> &num) {
    if (num.size() == 0) {
      return 0;
    }
    if (num.size() == 1) {
      return num[0];
    }
    vector<int> r(num.size());
    r[0] = num[0];
    r[1] = max(r[0], num[1]);
    for (int i = 2; i < num.size(); i++) {
      r[i] = max(r[i-1], num[i]+r[i-2]);
    }
    return r[num.size()-1];
  }
};

int main() {
  Solution s;
  int a[] = {2, 1, 1, 2};
  vector<int> num(a, a+4);

  int rob = s.rob(num);

  cout << "Total: " << rob << endl;
  return 0;
}