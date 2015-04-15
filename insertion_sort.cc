#include <iostream>
#include <vector>

using namespace std;

class Solution {
 public:
  void insertion_sort(vector<int>& num) {
    if (num.size() < 2) {
      return;
    }
    int tmp;
    int j;
    for (int i = 1; i < num.size(); i++) {
      tmp = num[i];
      j = i-1;
      while (j >= 0 && num[j] > tmp) {
        num[j+1] = num[j];
        j--;
      }
      num[j+1] = tmp;
    }
    return;
  }
};

int main() {
  Solution s;
  int arr[] = {5, 3, 6, 20, 23, 1, 4, 23, -4};
  vector<int> num(arr, arr+9);
  s.insertion_sort(num);

  for (int i = 0; i < num.size(); i++) {
    cout << num[i] << ", ";
  }
  cout << endl;
  return 0;
}