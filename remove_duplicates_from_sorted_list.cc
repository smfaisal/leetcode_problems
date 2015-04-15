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
  ListNode *deleteDuplicates(ListNode *head) {
    if (!head || !(head->next)) {
      return head;
    }

    ListNode* prev = NULL;
    ListNode* cur = head;
    ListNode* next = cur->next;

    while (next) {
      if (cur->val != next->val) {
//        free(cur);
//      } else {
        if (!prev) {
          head = cur;
        } else {
          prev->next = cur;
        }
        prev = cur;
      }
      cur = next;
      next = cur->next;
    }
    if (!prev) {
      head = cur;
    } else if (prev->next != cur) {
      prev->next = cur;
    }

    return head;
  }
};

int main() {
  ListNode n1(2);
  ListNode n2(2);
  ListNode n3(2);
  ListNode n4(2);
  ListNode n5(2);
  ListNode* head = &n1;
  n1.next = &n2;
  n2.next = &n3;
  n3.next = &n4;
  n4.next = &n5;

  ListNode* curr = head;
  cout << "Original list: ";
  while (curr) {
    cout << curr->val << "->";
    curr = curr->next;
  }
  cout << endl;

  Solution s;

  curr = s.deleteDuplicates(head);
  cout << "New list: ";
  while (curr) {
    cout << curr->val << "->";
    curr = curr->next;
  }
  cout << endl;
  return 0;
}
