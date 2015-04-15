#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
  void reorder(vector<int>& array1, vector<int>& array2) {
    if (array1.size() < 2) {
      return;
    }

    vector<int> ind(array1.size());

    for (int i = 0; i < array1.size(); i++) {
      ind[array1[i]] = i;
    }
    int tmp;
    for (int i = 0; i < array1.size(); i++) {
      if (array1[i] != array2[i]) {
        if (array1[i] == 0) {
          swap(array1[i], array1[ind[array2[i]]]);
        } else {
          swap(array1[i], array1[ind[0]]);
          tmp = ind[array1[i]];
          ind[array1[i]] = ind[0];
          ind[0] = tmp;
          swap(array1[i], array1[ind[array2[i]]]);
        }
      }
    }
  }
};

int main() {
  Solution s;
  int a1[] = {4, 1, 3, 0, 2};
  int a2[] = {3, 1, 0, 2, 4};

  vector<int> array1(a1, a1+5);
  vector<int> array2(a2, a2+5);

  s.reorder(array1, array2);

  for (int i = 0; i < array1.size(); i++) {
    cout << array1[i] << ", " << array2[i] << endl;
  }
  return 0;
}