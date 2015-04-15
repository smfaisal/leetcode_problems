#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

class Solution {
public:
  int threeSumClosest(vector<int> &num, int target) {
    int closest = 32767;

    if (num.size() < 3) {
      return closest;
    }
    sort(num.begin(), num.end());
    for (int i = 0; i < num.size()-2; i++) {
      //cout << "i: " << i << " num[i]: " << num[i] << endl;
      if (i > 0 && num[i-1] == num[i]) {
        continue;
      }
      for (int j = i+1; j < num.size()-1; j++) {
        //cout << "j: " << j << " num[j]: " << num[j] << endl;
        if (j > i+1 && num[j-1] == num[j]) {
          continue;
        }
        //if (num[i] + num[j] > target+closest) {
        //  break;
        //}
        for (int k = j+1; k < num.size(); k++) {
          //cout << "k: " << k << " num[k]: " << num[k] << endl;
          if (k > j+1 && num[k-1] == num[k]) {
            continue;
          }
          int sum = num[i] + num[j] + num[k];
          //cout << "Sum: " << sum << ", Target: " << target << ", ABS: "
          //<< abs(sum-target) << ", Closest: " << closest << endl;
          if (sum == target) {
            return target;
          } else if (abs(sum-target) < abs(target-closest)) {
            closest = sum;
          }
        }
      }
    }
    return closest;
  }
};

int main() {
  Solution s;
  int arr[] = {1, 1, 1, 1}; //{-1, 0, 1, 2, -1, -4};
  vector<int> num(arr, arr+4);
  cout << "Closest 3 sum is: " << s.threeSumClosest(num, 0) << endl;
  return 0;
}
