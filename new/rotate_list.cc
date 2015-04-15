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
    int len = 0;
    ListNode* cur = head;
    while (cur) {
      cur = cur->next;
      len++;
    }

    int rot = k%len;
    if (rot == 0) {
      return head;
    }
    ListNode* p = head;
    cur = head;
    for (int i = 0; i < rot; i++) {
      cur = cur->next;
    }
    while (cur->next) {
      p = p->next;
      cur = cur->next;
    }
    cur->next = head;
    head = p->next;
    p->next = NULL;
    return head;
  }
};

int main() {
  Solution s;
  ListNode n1(1);
//  ListNode n2(2);
//  ListNode n3(3);
//  ListNode n4(4);
//  ListNode n5(5);

  ListNode* head = &n1;
//  n1.next = &n2;
//  n2.next = &n3;
//  n3.next = &n4;
//  n4.next = &n5;

  ListNode* nhead = s.rotateRight(head, 99);

  cout << "New list: ";

  while (nhead) {
    cout << nhead->val << " -> ";
    nhead = nhead->next;
  }
  cout << endl;
  return 0;
}