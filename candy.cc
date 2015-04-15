#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int candy(vector<int> &ratings) {
    int res;
    vector<int> ltr;

    if (ratings.size() < 2) {
      return ratings.size();
    }

    int cnt = 1;

    ltr.push_back(cnt);
    for (int i = 1; i < ratings.size(); i++) {
      if (ratings[i] > ratings[i-1]) {
        cnt++;
        ltr.push_back(cnt);
      } else {
        cnt = 1;
        ltr.push_back(cnt);
      }

    }
    cnt = 1;
    ltr[ratings.size()-1] = max(cnt, ltr[ratings.size()-1]);
    res = ltr[ratings.size()-1];

    for (int i = ratings.size()-2; i >= 0; i--) {
      if (ratings[i] > ratings[i+1]) {
        cnt++;
      } else {
        cnt = 1;
      }
      ltr[i] = max(cnt, ltr[i]);
      res += ltr[i];
    }
    return res;
  }
};

int main() {
  vector<int> ratings;
  ratings.push_back(1);
  ratings.push_back(2);
  ratings.push_back(2);
  Solution s;
  cout << "Need: " << s.candy(ratings) << endl;
}