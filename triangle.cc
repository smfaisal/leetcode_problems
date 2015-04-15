#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int minimumTotal(vector<vector<int> > &triangle) {
    vector<int> min_sum;
    vector<int> row_sum;
    int sum;
    int mn;
    for (int i = 0; i < triangle.size(); i++) {
      row_sum.clear();
      mn = INT_MAX;
      for (int j = 0; j <= i; j++) {
        sum = triangle[i][j];
        if (i-1 >= 0 && j-1 >= 0) {
          mn = min_sum[j-1];
        }
        if (i-1 >= 0 && j >= 0 && j < triangle[i-1].size()) {
          mn = min(mn, min_sum[j]);
        }
        if (mn != INT_MAX) {
          sum += mn;
        }
        row_sum.push_back(sum);
      }
      min_sum.clear();
      min_sum = row_sum;
      //min_sum.push_back(row_sum);
    }
    //for (int x = 0; x < min_sum.size(); x++) {
      //for (int y = 0; y <= x; y++) {
      //  cout << min_sum[x] << ", ";
      //}
      //cout << endl;
      //}
    return *min_element(min_sum.begin(), min_sum.end());
  }
};

int main() {
  Solution s;
  vector<vector<int> > triangle;
  vector<int> row;
  row.push_back(-1);
  triangle.push_back(row);
  row.clear();
  row.push_back(2);
  row.push_back(3);
  triangle.push_back(row);
  row.clear();
  row.push_back(1);
  row.push_back(-1);
  row.push_back(-3);
  triangle.push_back(row);

  cout << "Smallest sum: " << s.minimumTotal(triangle) << endl;
  return 0;
}

