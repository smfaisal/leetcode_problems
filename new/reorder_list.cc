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
  ListNode* rev(ListNode* head) {
    if (!head) {
      return head;
    }
    ListNode* prev = NULL;
    ListNode* cur = head;
    ListNode* nxt;
    while (cur->next) {
      nxt = cur->next;
      cur->next = prev;
      prev = cur;
      cur = nxt;
    }
    cur->next = prev;
    head = cur;
    return head;
  }

  void reorderList(ListNode *head) {
    if (!head) {
      return;
    }
    ListNode* cur = head->next;
    ListNode* mid = head;
    while (cur && cur->next) {
      cur = cur->next->next;
      mid = mid->next;
    }
    mid->next = rev(mid->next);

    //    mid = mid->next;
    ListNode* tmp;
    cur = head;
    while (cur != mid) {
      tmp = mid->next;
      mid->next = mid->next->next;
      tmp->next = cur->next;
      cur->next = tmp;
      cur = cur->next->next;
    }
  }
};

int main() {
  ListNode n1(1);
  ListNode n2(2);
  ListNode n3(3);
  ListNode n4(4);
  ListNode n5(5);
  ListNode n6(6);

  n1.next = &n2;
  n2.next = &n3;
  n3.next = &n4;
  n4.next = &n5;
  n5.next = &n6;

  Solution s;
  ListNode* head = &n1;
  ListNode* curr = head;

  while (curr) {
    cout << curr->val << "->";
    curr = curr->next;
  }
  cout << endl;
  s.reorderList(head);

  curr = head;
  while (curr) {
    cout << curr->val << "->";
    curr = curr->next;
  }

  cout << endl;

  return 0;
}