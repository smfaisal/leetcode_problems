#include <iostream>
#include <vector>

#define LIMIT 100

using namespace std;

class Solution{
public:
  vector<int> counting_sort(vector<int>& num) {
    vector<int> c(LIMIT, 0);
    vector<int> sorted(num.size());
    for (int i = 0; i < num.size(); i++) {
      c[num[i]]++;
    }

    for (int i = 1; i < LIMIT; i++) {
      c[i] += c[i-1];
    }

    for (int i = num.size()-1; i >= 0; i--) {
      sorted[c[num[i]]-1] = num[i];
      c[num[i]]--;
    }
    return sorted;
  }
};

int main() {
  Solution s;
  int a[] = {12, 32, 2, 91, 32, 13, 8, 43, 89};
  vector<int> num(a, a+9);
  cout << "Original: " ;
  for (int i = 0; i < num.size(); i++) {
    cout << num[i] << ", ";
  }
  cout << endl;

  vector<int> sorted = s.counting_sort(num);

  cout << "Sorted: " ;
  for (int i = 0; i < sorted.size(); i++) {
    cout << sorted[i] << ", ";
  }
  cout << endl;
  return 0;
}