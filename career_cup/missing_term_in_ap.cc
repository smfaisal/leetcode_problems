#include <iostream>
#include <vector>

using namespace std;

int main() {
  int N;
  vector<int> series;

  cin >> N;
  int t;
  for (int i = 0; i < N; i++) {
    cin >> t;
    series.push_back(t);
  }

  int min_d = min(series[1]-series[0], series[2]-series[1]);
  for (int i = 0; i < N-1; i++) {
    if (series[i+1] != series[i]+min_d) {
      cout << series[i]+min_d;
      break;
    }
  }
  return 0;
}

