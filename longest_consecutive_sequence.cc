#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  void radix_sort(vector<int>& num) {
    vector<int> pos;
    vector<int> neg;
    for (int i = 0; i < num.size(); i++) {
      if (num[i] >= 0) {
        pos.push_back(num[i]);
      } else {
        neg.push_back(-num[i]);
      }
    }

    num.clear();
    vector<int> c(10);

    vector<int> sorted(neg.size());
    vector<int> tmp(neg.begin(), neg.end());

    int base = 10;
    int exp = 1;
    int m;

    if (neg.size() > 0) {
      m = neg[0];

      for (int i = 1; i < neg.size(); i++) {
        if (neg[i] > m) {
          m = neg[i];
        }
      }
      bool tmptosorted = true;
      vector<int>& unsrt = tmp;
      vector<int>& srt = sorted;

      while (m / exp > 0) {
        for (int i = 0; i < 10; i++) {
          c[i] = 0;
        }
        for (int i = 0; i < unsrt.size(); i++) {
          c[(unsrt[i]/exp)%10]++;
        }
        for (int i = 1; i < 10; i++) {
          c[i] += c[i-1];
        }
        for (int i = unsrt.size()-1; i >= 0; i--) {
          srt[c[(unsrt[i]/exp)%10]-1] = unsrt[i];
          c[(unsrt[i]/exp)%10]--;
        }
        vector<int>& t = unsrt;
        unsrt = srt;
        srt = t;
        exp *= base;
      }
      for (int i = srt.size()-1; i>= 0; i--) {
//        cout << srt[i] << " " << endl;
        num.push_back(-srt[i]);
      }
    }
    if (pos.size() > 0) {
//      cout << "pos[0]: " << pos[0] << endl;
      exp = 1;
      base = 10;
      m = pos[0];
      sorted = pos;
      tmp = pos;
      for (int i = 1; i < pos.size(); i++) {
        if (pos[i] > m) {
          m = pos[i];
        }
      }
      bool tmptosorted = true;
      vector<int>& unsrt = tmp;
      vector<int>& srt = sorted;

      while (m / exp > 0) {
        for (int i = 0; i < 10; i++) {
          c[i] = 0;
        }
        for (int i = 0; i < unsrt.size(); i++) {
          c[(unsrt[i]/exp)%10]++;
        }
        for (int i = 1; i < 10; i++) {
          c[i] += c[i-1];
        }
        for (int i = unsrt.size()-1; i >= 0; i--) {
          srt[c[(unsrt[i]/exp)%10]-1] = unsrt[i];
          c[(unsrt[i]/exp)%10]--;
        }
        vector<int>& t = unsrt;
        unsrt = srt;
        srt = t;
        exp *= base;
      }
      for (int i = 0; i < srt.size(); i++) {
//        cout << srt[i] << " " << endl;
        num.push_back(srt[i]);
      }
    }
  }

  int longestConsecutive(vector<int> &num) {
    if (num.size() < 2) {
      return num.size();
    }

    radix_sort(num);
//    for (int i = 0; i < num.size(); i++) {
//      cout << num[i] << ", ";
//    }
//    cout << endl;

    int len = 1;
    int max_len = INT_MIN;
    int seq_st = 0;
    int seq_end;
    int i;
    for (i = 1; i < num.size(); i++) {
      if (num[i] == num[i-1]) {
        continue;
      } else if (num[i]-num[i-1] == 1) {
        len++;
      } else {
        if (len > max_len) {
          max_len = len;
        }
        len = 1;
      }
    }
    if (len > max_len) {
      max_len = len;
    }
//    for (i = 1; i < num.size(); i++) {
//      if (num[i] - num[i-1] > 1) {
//        seq_end = i-1;
//        while (seq_end > 0 && num[seq_end] == num[seq_end-1]) {
//          seq_end--;
//        }
//        len = seq_end-seq_st+1;
//        if (len > max_len) {
//          max_len = len;
//        }
//        seq_st = i;
//      }
//    }
//    seq_end = i-1;
//    while (seq_end > 0 && num[seq_end] == num[seq_end-1]) {
//      seq_end--;
//    }
//    len = seq_end-seq_st+1;
//    if (len > max_len) {
//      max_len = len;
//    }

    return max_len;
  }
};

int main() {
  Solution s;
  int a[] = {0, 1, 2, 1}; //{100, 4, -200, 1, 2, 3};
  vector<int> num(a, a+4);
  cout << "Original: " ;
  for (int i = 0; i < num.size(); i++) {
    cout << num[i] << ", ";
  }
  cout << endl;

  int max_len = s.longestConsecutive(num);
  cout << "Max consecutive len: " << max_len << endl;
  return 0;
}