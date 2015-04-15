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
  ListNode *partition(ListNode *head, int x) {
    if (!head || !(head->next)) {
      return head;
    }
    ListNode* insert_ptr = NULL;
    ListNode* curr = head;
    ListNode* prev = NULL;

    while (curr) {
      if (curr->val <x) {
        if (!insert_ptr) {
          if (!prev) {
            insert_ptr = curr;
            prev = curr;
            curr = curr->next;
          } else {
            prev->next = curr->next;
            curr->next = head;
            head = curr;
            insert_ptr = head;
            curr = prev->next;
          }
        } else if (curr != insert_ptr->next) {
          prev->next = curr->next;
          curr->next = insert_ptr->next;
          insert_ptr->next = curr;
          insert_ptr = insert_ptr->next;
          curr = prev->next;
        } else {
          prev = curr;
          curr = curr->next;
          insert_ptr = insert_ptr->next;
        }
      } else {
        prev = curr;
        curr = curr->next;
      }
    }
    return head;
  }
};

int main() {
  ListNode n1(5);
  ListNode n2(4);
  ListNode n3(3);
  ListNode n4(3);
  ListNode n5(3);
  ListNode* head = &n1;
  n1.next = &n2;
  n2.next = &n3;
  n3.next = &n4;
  n4.next = &n5;

  Solution s;

  ListNode* curr = head;
  cout << "Original list: ";
  while (curr) {
    cout << curr->val << "->";
    curr = curr->next;
  }
  cout << endl;
  curr = s.partition(head,6);
  cout << "New list: ";
  while (curr) {
    cout << curr->val << "->";
    curr = curr->next;
  }
  cout << endl;
  return 0;
}