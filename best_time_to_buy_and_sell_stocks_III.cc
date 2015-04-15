#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
  int getMaxProfit(vector<int>& prices, int st, int end) {
    if (st > end) {
      return 0;
    }
    int cur_min = prices[st];
    int max_profit = INT_MIN;

    for (int i = st+1; i <= end; i++) {
      if (cur_min > prices[i]) {
        cur_min = prices[i];
      }
      if (prices[i] - cur_min > max_profit) {
        max_profit = prices[i] - cur_min;
      }
    }
    return max_profit;
  }

  int maxProfit(vector<int> &prices) {
    if (prices.size() < 2) {
      return 0;
    }

    int profit = INT_MIN;
    int m_profit = INT_MIN;

    for (int i = 1; i < prices.size(); i++) {
      if (prices[i] < prices[i-1]) {
        profit = getMaxProfit(prices, 0, i-1) + getMaxProfit(prices, i, prices.size()-1);
        if (profit > m_profit) {
          m_profit = profit;
        }
      }
    }
    return m_profit;
  }
};

int main() {
  Solution s;
  int a[] = {1,2,4,2,5,7,2,4,9,0};
  vector<int> prices(a, a+10);

  cout << "Max Profit: " << s.maxProfit(prices) << endl;

  return 0;
}