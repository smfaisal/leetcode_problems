#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
    int start = 0;
    int size = 0;
    int n = gas.size();
    int tank = 0;

    while (1) {
      if (size >= n) {
        return start;
      }
      int net = 0;
      if (start + size >= n) {
        net = gas[start+size-n]-cost[start+size-n];
      } else {
        net = gas[start+size]-cost[start+size];
      }
      if (tank + net < 0) {
        size++;
        start = start+size;
        if (start >= n) {
          return -1;
        }
        size = 0;
        tank = 0;
      } else {
        tank = tank + net;
        size++;
      }
    }
  }
};

int main() {
  int g[] = {1, 2};
  int c[] = {2, 1};
  vector<int> gas(g, g+2);
  vector<int> cost(c, c+2);

  Solution s;

  cout << "Start at: " << s.canCompleteCircuit(gas, cost) << endl;
}