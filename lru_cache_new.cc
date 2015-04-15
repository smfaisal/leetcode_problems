#include <iostream>
#include <unordered_map>

using namespace std;

class LRUCache{
public:
  LRUCache(int capacity) {
    cap = capacity;
    size = 0;
    head = NULL;
    tail = NULL;
  }

  int get(int key) {
    if (index.size() == 0) {
      return -1;
    } else if (index.find(key) == index.end()) {
      return -1;
    } else {
      // cache access, so bring it to the front
      Item* item = index[key];
      if (item != head) {
        if (item != tail) {
          item->next->prev = item->prev;
        } else {
          if (item->prev) {
            tail = item->prev;
          } else {
            tail = item;
          }
        }

        item->prev->next = item->next;
        head->prev = item;
        item->next = head;
        item->prev = NULL;
        head = item;
      }
      return head->value;
    }
  }

  void set(int key, int value) {
    if (index.find(key) != index.end()) {
      Item* item = index[key];
      item->value = value;
      if (item != head) {
        if (item != tail) {
          item->next->prev = item->prev;
        } else {
          if (item->prev) {
            tail = item->prev;
          } else {
            tail = item;
          }
        }
        item->prev->next = item->next;
        head->prev = item;
        item->next = head;
        item->prev = NULL;
        head = item;
      }
    } else {
      // Not in cache
      Item* item = new Item(key, value);
      if (index.size() >= cap) {
        // remove the least used
        Item* last = tail;
        if (head == tail) {
          tail = NULL;
        } else {
          tail = tail->prev;
          tail->next = NULL;
        }
        index.erase(last->key);
        delete last;
      }
      if (index.size() < cap) {
        if (head == NULL) {
          head = item;
          tail = item;
        } else {
          item->next = head;
          head->prev = item;
          head = item;
        }
      }
      index[key] = item;
    }
  }

private:
  struct Item{
    int key;
    int value;
    Item* prev;
    Item* next;
    Item(int k, int v) : key(k), value(v), prev(NULL), next(NULL) {}
  };

  Item* head;
  Item* tail;
  int cap;
  int size;
  unordered_map<int, Item*> index;
};


int main() {
  LRUCache c(2);
  c.set(2, 1);
//  cout << "for 1: " << c.get(1) << endl;
  c.set(1, 1);
  cout << "for 2: " << c.get(2) << endl;
  c.set(4, 1);
  cout << "for 1: " << c.get(1) << endl;
  cout << "for 2: " << c.get(2) << endl;
//  c.set(3, 30);
//  cout << "for 3: " << c.get(3) << endl;
//  c.set(4, 40);
//  cout << "for 1: " << c.get(1) << endl;

  return 0;
}