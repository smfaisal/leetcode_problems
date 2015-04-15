#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *rotateRight(ListNode *head, int k) {
    if (!head || k == 0) {
      return head;
    }
    ListNode* tor;
    ListNode* hare;

    tor = head;
    for (int i = 0; i < k; i++) {
      tor = tor->next;
      if (!tor) {
        tor = head;
      }
    }
    if (tor == head) {
      return head;
    }
    hare = head;
    while (tor->next) {
      tor = tor->next;
      hare = hare->next;
    }

    ListNode* newhead = hare->next;
    hare->next = NULL;
    tor->next = head;
    head = newhead;
    return head;
  }
};

int main() {
  Solution s;
  ListNode n1(1);
  ListNode n2(2);
  ListNode n3(3);
  ListNode n4(4);
  ListNode n5(5);

  ListNode* head = &n1;
  n1.next = &n2;
  n2.next = &n3;
  n3.next = &n4;
  n4.next = &n5;

  ListNode* nhead = s.rotateRight(head, 5);

  cout << "New list: ";

  while (nhead) {
    cout << nhead->val << " -> ";
    nhead = nhead->next;
  }
  cout << endl;
  return 0;
}