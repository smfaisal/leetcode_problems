#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  void nextPermutation(vector<int> &num) {
    if (num.size() < 2) {
      return;
    }
    int i, j;
    for (i = num.size()-2; i >= 0; i--) {
      if (num[i] < num[i+1]) {
        break;
      }
    }

    int tmp;

    if (i >= 0) {
      for (j = i+1; j < num.size(); j++) {
        if (num[j] > num[i]) {
          tmp = j;
        }
      }
      swap(num[i], num[tmp]);
    }
    reverse(num.begin()+i+1, num.end());
  }
};

int main() {
  Solution s;
  int arr[] = {4,2,0,2,3,2,0};
  vector<int> num(arr, arr+7);
  cout << "Current permutation: ";
  for (int i = 0; i < num.size(); i++) {
    cout << num[i] << ", ";
  }
  cout << endl;
  s.nextPermutation(num);
  cout << "Next permutation: ";
  for (int i = 0; i < num.size(); i++) {
    cout << num[i] << ", ";
  }
  cout << endl;
}
