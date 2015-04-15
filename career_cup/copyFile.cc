#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <unordered_set>

using namespace std;

int main() {
  int n_datacenters;
  cin >> n_datacenters;
//  cout << n_datacenters;
  int n_ds;
  int num;
  char c[1000];
  cin.clear();
  cin.getline(c, sizeof(c));
  vector<unordered_set<int> > ds_map(n_datacenters, unordered_set<int>());
  unordered_set<int> datasets;

  for (int i = 1; i <= n_datacenters; i++) {
//    cout << "here: " << endl;
    cin.clear();
    cin.getline(c, sizeof(c));
    string in(c);
    istringstream iss(in);
    iss >> n_ds;
    while (!(iss >> num).fail()) {
      ds_map[i-1].insert(num);
      datasets.insert(num);
//      cout << num << endl;
    }
  }
  bool first = true;
  unordered_set<int>::iterator it;
  for (int i = 0; i < n_datacenters; i++) {
    for (it = datasets.begin(); it != datasets.end(); it++) {
      if (ds_map[i].find(*it) == ds_map[i].end()) {
        if (first) {
          first = false;
        } else {
          cout << endl;
        }
        cout << *it << " ";
        for (int j = 0; j < n_datacenters; j++) {
          if (ds_map[j].find(*it) != ds_map[j].end()) {
            cout << j+1 << " " << i+1;
            break;
          }
        }
      }
    }
  }
  if (!first) {
    cout << endl;
  }
  cout << "done";
}