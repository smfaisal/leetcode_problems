#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int m, int n) {
    if (n == 0 || !head) {
      return head;
    }
    ListNode* prev, *cur, *next;

    prev = NULL;
    cur = head;

    for (int i = 1; i < m && cur; i++) {
      prev = cur;
      cur = cur->next;
    }
    if (!cur) {
      return head;
    }
    ListNode* reg_st = cur;
    ListNode* reg_prev = prev;

    for (int i = m; i < n && cur; i++) {
      cur = cur->next;
    }
    if (!cur) {
      return head;
    }
    ListNode* reg_end = cur;
    ListNode* reg_next = cur->next;
    prev = reg_prev;
    cur = reg_st;
    next = cur->next;
    ListNode* tmp;
    cur->next = reg_next;

    while (next && next != reg_next) {
      tmp = next->next;
      next->next = cur;
      cur = next;
      next = tmp;
    }
    if (next == reg_next) {
      if (reg_prev == NULL) {
        head = cur;
      } else {
        reg_prev->next = cur;
      }
    }

    return head;
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
  head = s.reverseBetween(head, 2, 4);

  curr = head;
  while (curr) {
    cout << curr->val << "->";
    curr = curr->next;
  }

  cout << endl;

  return 0;
}
