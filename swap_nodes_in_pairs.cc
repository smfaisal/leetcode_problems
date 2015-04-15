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
  ListNode *swapPairs(ListNode *head) {
    if (!head || !(head->next)) {
      return head;
    }
    ListNode* curr = head;
    head = head->next;
    curr->next = head->next;
    head->next = curr;
    ListNode* prev = curr;
    curr = curr->next;

    while (curr && curr->next) {
      prev->next = curr->next;
      curr->next = curr->next->next;
      prev->next->next = curr;
      prev = curr;
      curr = curr->next;
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
  ListNode* head = &n1;
  n1.next = &n2;
  n2.next = &n3;
  n3.next = &n4;
  n4.next = &n5;

  Solution s;

  ListNode* curr = s.swapPairs(head);

  while (curr) {
    cout << curr->val << "->";
    curr = curr->next;
  }
  cout << endl;
  return 0;
}
