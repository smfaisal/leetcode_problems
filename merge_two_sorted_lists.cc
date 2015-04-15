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
  ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (!l1) {
      return l2;
    }
    if (!l2) {
      return l1;
    }
    ListNode* head;
    if (l1->val < l2->val) {
      head = l1;
      l1 = l1->next;
    } else {
      head = l2;
      l2 = l2->next;
    }

    ListNode* cur = head;
    while (l1 && l2) {
      if (l1->val < l2->val) {
        cur->next = l1;
        l1 = l1->next;
      } else {
        cur->next = l2;
        l2 = l2->next;
      }
      cur = cur->next;
    }
    if (l1) {
      cur->next = l1;
    } else if (l2) {
      cur->next = l2;
    }
    return head;
  }
};

int main() {
  Solution s;
  ListNode n1(1), n2(2), n3(3), n4(4), n5(5);
  n1.next = &n2;
  n2.next = &n3;
  n3.next = &n4;
  n4.next = &n5;

  ListNode* head = &n1;

  ListNode m1(1), m2(2), m3(3), m4(4), m5(5);
  m1.next = &m2;
  m2.next = &m3;
  m3.next = &m4;
  m4.next = &m5;

  ListNode* head1 = &m1;

  while (head) {
    cout << head->val << " -> ";
    head = head->next;
  }
  cout << endl;

  while (head1) {
    cout << head1->val << " -> ";
    head1 = head1->next;
  }
  cout << endl;

  head = s.mergeTwoLists(&n1, &m1);
  while (head) {
    cout << head->val << " -> ";
    head = head->next;
  }
  cout << endl;

  return 0;
}