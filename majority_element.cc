#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int majorityElement(vector<int> &num) {
    int maj = num[0];
    int len = 1;

    for (int i = 1; i < num.size(); i++) {
      if (num[i] == maj) {
        len++;
      } else {
        len--;
      }
      if (len == 0) {
        maj = num[i];
        len = 1;
      }
    }
    return maj;
  }
};

int main() {
  Solution s;
  int a[] = {1, 2, 1, 2, 1, 1, 1, 43, 25, 1, 2};
  vector<int> num(a, a+11);
  int maj = s.majorityElement(num);

  cout << "Majority Element: " << maj << endl;

  return 0;
}