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
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    if (!head) {
      return head;
    }
    ListNode* prev = head;
    ListNode* curr = head;
    ListNode* nth = head;
    for (int i = 0; i < n; i++) {
      if (nth) {
        nth = nth->next;
      } else {
        return head;
      }
    }

    while (nth) {
      prev = curr;
      curr = curr->next;
      nth = nth->next;
    }

    if (curr != head) {
      prev->next = curr->next;
    } else {
      head = curr->next;
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

  ListNode* curr = &n1;

  while (curr) {
    cout << curr->val << "->";
    curr = curr->next;
  }
  cout << endl;
  head = s.removeNthFromEnd(&n1, 2);

  curr = head;
  while (curr) {
    cout << curr->val << "->";
    curr = curr->next;
  }

  cout << endl;

  return 0;
}