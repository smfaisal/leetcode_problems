#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    if (prices.size() < 2) {
      return 0;
    }

    int cur_min = prices[0];
    int max_profit = INT_MIN;

    for (int i = 1; i < prices.size(); i++) {
      if (cur_min > prices[i]) {
        cur_min = prices[i];
      }
      if (prices[i] - cur_min > max_profit) {
        max_profit = prices[i] - cur_min;
      }
    }
    return max_profit;
  }
};

int main() {
  Solution s;
  int a[] = {5, 8, 3, 8, 2, 4};
  vector<int> prices(a, a+6);

  cout << "Max Profit: " << s.maxProfit(prices) << endl;

  return 0;
}