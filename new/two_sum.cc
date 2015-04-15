#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> twoSum(vector<int> &numbers, int target) {
    vector<int> res;

    if (numbers.size() == 0) {
      return res;
    }

    sort(numbers.begin(), numbers.end());

    int st = 0;
    int end = numbers.size()-1;

    while (st <= end) {
      if (numbers[st]+numbers[end] == target) {
        res.push_back(st+1);
        res.push_back(end+1);
        return res;
      } else if (numbers[st]+numbers[end] < target) {
        st++;
      } else {
        end--;
      }
    }

    return res;
  }
};

int main() {
  Solution s;
  int a[] = {2, 7, 11, 15};
  vector<int> numbers(a, a+4);
  vector<int> res = s.twoSum(numbers, 9);

  cout << "Res: " << res[0] << ", " << res[1] << endl;
  return 0;
}