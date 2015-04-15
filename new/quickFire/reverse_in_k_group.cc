#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x):val(x), next(NULL) {}
};

class Solution{
public:
  ListNode* reverse(ListNode* head, int k) {
    if (!head || !k) {
      return head;
    }

    ListNode* newhead = new ListNode(0);
    newhead->next = head;
    ListNode* prev = newhead;
    ListNode* last = head;

    for (int i = 1; i < k; i++) {
      last = last->next;
      if (!last) {
        return newhead->next;
      }
    }
    ListNode* tmp;
    while (1) {
      while (prev->next != last) {
        tmp = prev->next;
        prev->next = prev->next->next;
        tmp->next = last->next;
        last->next = tmp;
      }
      for (int i = 0; i < k; i++) {
        prev = prev->next;
        last = last->next;
        if (!last) {
          return newhead->next;
        }
      }
    }
//    newhead->next;
  }
};

int main() {
  ListNode n1(1);
  ListNode n2(2);
  ListNode n3(3);
  ListNode n4(4);
  ListNode n5(5);
  n1.next = &n2;
  n2.next = &n3;
  n3.next = &n4;
  n4.next = &n5;

  Solution s;
  ListNode* head = &n1;
  ListNode* curr = head;

  while (curr) {
    cout << curr->val << "->";
    curr = curr->next;
  }
  cout << endl;
  head = s.reverse(head, 3);

  curr = head;
  while (curr) {
    cout << curr->val << "->";
    curr = curr->next;
  }

  cout << endl;

  return 0;
}