#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:

  int maxProfit(vector<int> &prices) {
    if (prices.size() < 2) {
      return 0;
    }

    vector<int> profit(prices.size(), 0);
    int mprof = 0;
    int st = prices[0];
    for (int i = 1; i < prices.size(); i++) {
//      cout << "i, i+j-1: " << i << ", " << i+j-1 << endl;
      if (mprof < prices[i] - st) {
        mprof = prices[i]-st;
      }
      if (st > prices[i]) {
        st = prices[i];
      }
      profit[i] = mprof;
    }

    int ed = prices[prices.size()-1];
    int max_profit = INT_MIN;

    for (int i = prices.size()-1; i >= 0; i--) {
      if (max_profit < ed-prices[i] + profit[i-1]) {
        max_profit = ed-prices[i] + profit[i-1];
      }
      if (ed < prices[i]) {
        ed = prices[i];
      }
    }

    return max_profit;
  }
};

int main() {
  Solution s;
  int a[] = {1,2,4,2,5,7,2,4,9,0};
  vector<int> prices(a, a+10);

  cout << "Max Profit: " << s.maxProfit(prices) << endl;

  return 0;
}