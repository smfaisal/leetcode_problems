#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
 public:
  void nextPermutation(vector<int> &num) {
    // Find out a change point where digit value decreases
    int i = num.size()-2;
    int j;
    while (i  >= 0 && num[i] >= num[i+1]) {
      --i;
    }

    //
    if (i >= 0) {

      // Find smallest that is greater than num[i];
      int l;
      for (j = 0; j < num.size(); j++) {
        if (num[j] > num[i]) {
          l = j;
        }
      }
      swap (num[i], num[l]);
      }

    std::reverse(num.begin() + i + 1, num.end());
  }
};

int main() {
  Solution s;
  int arr[] = {5, 1, 1};
  vector<int> num(arr, arr+3);
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