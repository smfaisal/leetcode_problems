#include <iostream>
#include <functional>
#include <unordered_set>

using namespace std;

struct mystruct{
  int i;
  string s;
  mystruct(int i, string s):i(i), s(s) {}
  bool operator==(const mystruct& m) const {
    return (i == m.i && s == m.s);
  }
};

mystruct operator+(const mystruct& m1, const mystruct& m2) {
  return mystruct(m1.i+m2.i, m1.s+m2.s);
}

template <>
struct hash<mystruct> {
  size_t operator()(const mystruct& m) {
    size_t h = 0;
    h = hash<int>()(m.i) ^ hash<string>()(m.s);
    return h;
  }
};

int main() {
  unordered_set<mystruct> myset;

  mystruct m1(1, "hello");
  mystruct m2(2, "world");

  myset.insert(m1);
  myset.insert(m2);
  unordered_set<mystruct>::iterator it;
  cout << "myset content: " << endl;
  for (it = myset.begin(); it != myset.end(); it++) {
    cout << "i: " << it->i << " s: " << it->s << endl;
  }

  mystruct m3(m1);
  mystruct m4 = m1+m2;

  if (myset.find(m3) != myset.end()) {
    cout << "m3 is found in the set" << endl;
  }
  return 0;
}