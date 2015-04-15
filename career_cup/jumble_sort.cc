#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;

string numToStr(int n) {
  stringstream ss;
  ss << n;
  return ss.str();
}

int main() {
  char c[1001];
  vector<string> str_vec;
  vector<int> num_vec;
  vector<bool> smap;
  int num;
  string tmp;
  cin.getline(c, sizeof(c));
  string in(c);

  int i;
  int ind = 0;
  for ( i = 0; i < in.size(); i++) {
    if (in[i] == ' ') {
      tmp = in.substr(ind, i-ind);
      ind = i+1;
      istringstream iss(tmp);
      if (!(iss >> num).fail()) {
        smap.push_back(false);
        num_vec.push_back(num);
      } else {
        smap.push_back(true);
        str_vec.push_back(tmp);
      }
    }
  }
  if (ind < i) {
    tmp = in.substr(ind, i-ind);
    istringstream iss(tmp);
    if (!(iss >> num).fail()) {
      smap.push_back(false);
      num_vec.push_back(num);
    } else {
      smap.push_back(true);
      str_vec.push_back(tmp);
    }

  }

  sort(str_vec.begin(), str_vec.end());
  sort(num_vec.begin(), num_vec.end());

  string out;
  vector<string>::iterator sit = str_vec.begin();
  vector<int>::iterator nit = num_vec.begin();

  for (i = 0; i < smap.size(); i++) {
    if (smap[i]) {
      out += *sit;
      sit++;
    } else {
      out += numToStr(*nit);
      nit++;
    }
    if (i < smap.size()-1) {
      out += " ";
    }
  }
  cout << out;
}