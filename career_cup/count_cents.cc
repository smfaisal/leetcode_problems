#include <iostream>
#include <vector>

using namespace std;

class Solution{
public:
  void dfs(int n, int ind, vector<int>& coins, int& ways) {
    if (n == 0) {
      ways++;
      return;
    }
    if (ind >= coins.size()) {
      return;
    }
    if (coins[ind] > n) {
      return;
    } else {
      dfs(n-coins[ind], ind, coins, ways);
      dfs(n, ind+1, coins, ways);
    }
  }
  int countWays(int n, vector<int>& coins) {
    if (n == 0 || coins.size() == 0) {
      return 0;
    }

    int ways = 0;
    dfs(n, 0, coins, ways);
    return ways;
  }
};

int main() {
  Solution s;
  int c[] = {1, 5, 10, 25};
  vector<int> coins(c, c+4);
  int res = s.countWays(100, coins);
  cout << "Ways: " << res << endl;
  return 0;
}