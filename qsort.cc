#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void qsort(vector<int>& num, int st, int end) {
    if (end <= st) {
      return;
    }
    int item = num[end];
    int j = st-1;
    for (int i = st; i < end; i++) {
      if (num[i] < item) {
        swap(num[j+1], num[i]);
        j++;
      }
    }
    cout << "Swap: " << num[j+1] << ", " << num[end] << endl;
    swap(num[j+1], num[end]);
    cout << "qsort: " << st << " to " << j << " ";
    qsort(num, st, j);
    cout << "qsort: " << j+2 << " to " << endl;
    qsort(num, j+2, end);
  }
};

int main() {
  Solution s;
  int arr[] = {5, 3, 6, 20, 23, 1, 4, 23, -4};
  vector<int> num(arr, arr+9);
  s.qsort(num, 0, num.size()-1);

  for (int i = 0; i < num.size(); i++) {
    cout << num[i] << ", ";
  }
  cout << endl;
  return 0;
}