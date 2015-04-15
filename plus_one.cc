#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> plusOne(vector<int> &digits) {
    vector<int> result;

    if (digits.size() == 0) {
      return result;
    }
    int len = digits.size()-1;

    int r = digits[len--]+1;
    int carry = r/10;
    r = r%10;

    result.push_back(r);

    while (len >= 0) {
      r = digits[len--]+carry;
      carry = r/10;
      r = r%10;
      result.push_back(r);
    }
    if (carry > 0) {
      result.push_back(carry);
    }

    std::reverse(result.begin(), result.end());
    return result;
  }
};

int main() {
  Solution s;
  int arr[] = {9, 9 , 9, 9};
  vector<int> digits(arr, arr+4);
  vector<int> result = s.plusOne(digits);

  for (int i = 0; i < result.size(); i++) {
    cout << result[i] << ", ";
  }
  cout << endl;
  return 0;
}