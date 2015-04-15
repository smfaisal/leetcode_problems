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
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (!head || k == 0) {
      return head;
    }
    int len = 0;
    ListNode* nhead = new ListNode(0);
    ListNode* prev = nhead;
    ListNode* cur = head;
    ListNode* last = head;
    for (int i = 1; i < k; i++) {
      last = last->next;
      if (!last) {
        return head;
      }
    }
    ListNode* q = last->next;
    while (1) {
      if (!last) {
        return nhead->next;
      }
      q = last->next;
      while (cur != last) {
        prev->next = cur->next;
        cur->next = last->next;
        last->next = cur;
        cur = prev->next;
      }
      last = q;
      for (int i = 1; i < k; i++) {
        if (!last) {
          return nhead->next;
        }
        last = last->next;
      }
    }
    return nhead->next;
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
  head = s.reverseKGroup(head, 3);

  curr = head;
  while (curr) {
    cout << curr->val << "->";
    curr = curr->next;
  }

  cout << endl;

  return 0;
}