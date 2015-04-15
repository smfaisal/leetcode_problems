#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int maxProfit(vector<int> &prices) {
    if (prices.size() < 2) {
      return 0;
    }

    //vector<int> profit(prices.size(), 0);
    int cur_min = prices[0];
    int max_profit = 0;
    int cur_max_profit = 0;

    for (int i = 1; i < prices.size(); i++) {
      if (cur_min > prices[i] || prices[i] < prices[i-1]) {
        cur_min = prices[i];
        max_profit += cur_max_profit;
        cur_max_profit = 0;
      }
      if (prices[i] - cur_min > cur_max_profit) {
        cur_max_profit = prices[i] - cur_min;
      }
    }
    max_profit += cur_max_profit;
    return max_profit;
  }
};

int main() {
  Solution s;
  int a[] = {6, 1, 3, 2, 4, 7};
  vector<int> prices(a, a+6);

  cout << "Max Profit: " << s.maxProfit(prices) << endl;

  return 0;
}