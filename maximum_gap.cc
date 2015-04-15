#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void radix_sort(vector<int>& num) {
    vector<int> pos(num.begin(), num.end());

    num.clear();
    vector<int> c(10);

    vector<int> sorted = pos;
    vector<int> tmp = pos;

    int base = 10;
    int exp = 1;
    int m;

    //      cout << "pos[0]: " << pos[0] << endl;
    exp = 1;
    base = 10;
    m = pos[0];

    for (int i = 1; i < pos.size(); i++) {
      if (pos[i] > m) {
        m = pos[i];
      }
    }
    bool tmptosorted = true;
    vector<int>& unsrt = tmp;
    vector<int>& srt = sorted;

    while (m / exp > 0) {
      for (int i = 0; i < 10; i++) {
        c[i] = 0;
      }
      for (int i = 0; i < unsrt.size(); i++) {
        c[(unsrt[i]/exp)%10]++;
      }
      for (int i = 1; i < 10; i++) {
        c[i] += c[i-1];
      }
      for (int i = unsrt.size()-1; i >= 0; i--) {
        srt[c[(unsrt[i]/exp)%10]-1] = unsrt[i];
        c[(unsrt[i]/exp)%10]--;
      }
      vector<int>& t = unsrt;
      unsrt = srt;
      srt = t;
      exp *= base;
    }
    for (int i = 0; i < srt.size(); i++) {
      //        cout << srt[i] << " " << endl;
      num.push_back(srt[i]);
    }

  }

  int maximumGap(vector<int> &num) {
    if (num.size() < 2) {
      return 0;
    }
    radix_sort(num);

    int max_gap = INT_MIN;

    for (int i = 1; i < num.size(); i++) {
      if (num[i]-num[i-1] > max_gap) {
        max_gap = num[i]-num[i-1];
      }
    }
    return max_gap;
  }
};

int main() {
  Solution s;
  int a[] = {100, 4, 200, 1, 2, 3};
  vector<int> num(a, a+6);
  cout << "Original: " ;
  for (int i = 0; i < num.size(); i++) {
    cout << num[i] << ", ";
  }
  cout << endl;

  int max_gap = s.maximumGap(num);
  cout << "Max gap: " << max_gap << endl;
  return 0;
}