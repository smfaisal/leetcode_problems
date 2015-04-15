#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class LRUCache{
public:
  LRUCache(int capacity) {
    cap = capacity;
  }

  int get(int key) {
    int i;
    for (i = cache.size()-1; i >= 0; i--) {
      if (cache[i].first == key) {
        break;
      }
    }
    if (i >= 0) {
      mypair tmp = cache[i];
      while (i > 0) {
        cache[i] = cache[i-1];
        i--;
      }
      cache[0] = tmp;
      return tmp.second;
    } else {
      return -1;
    }
  }

  void set(int key, int value) {
    int i;
    for (i = cache.size()-1; i >= 0; i--) {
      if (cache[i].first == key) {
        break;
      }
    }
    if (i >= 0) {
      // found in cache
      mypair tmp = cache[i];
      i--;
      while (i >= 0) {
        cache[i+1] = cache[i];
        i--;
      }
      tmp.second = value;
      cache[0] = tmp;
    } else {
      // Not in cache
//      cout << "key: " << key << " val: " << value << " cap: " << cap << " size: " << cache.size() << endl;
      if (cache.size() < cap) {
        cache.resize(cache.size()+1);
      }
      for (i = cache.size()-1; i > 0; i--) {
        cache[i] = cache[i-1];
      }
      cache[0] = make_pair(key, value);
    }

  }

private:
  typedef pair<int, int> mypair;
  int cap;
  vector<mypair> cache;
//  unordered_map<int, int> index;
};

int main() {
  LRUCache c(3);
  c.set(1, 10);
  c.set(2, 20);
  cout << "for 2: " << c.get(2) << endl;
  c.set(2, 30);
  cout << "for 2: " << c.get(2) << endl;
  c.set(3, 30);
  c.set(4, 40);
    cout << "for 1: " << c.get(1) << endl;

  return 0;
}