#include <iostream>

using namespace std;

struct ListNode{
  int val;
  ListNode* next;
  ListNode(int x):val(x), next(NULL) {}
};

class Solution{
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (!head || k == 0) {
      return head;
    }
    ListNode* last = head;
    for (int i = 1; i < k; i++) {
      last = last->next;
      if (!last) {
        return head;
      }
    }
    ListNode* newhead = new ListNode(0);
    newhead->next = head;
    ListNode* prev = newhead;
    ListNode* curr = head;
    ListNode* nxt;

    while (1) {
      while (prev->next != last) {
        curr = prev->next;
        prev->next = curr->next;
        curr->next = last->next;
        last->next = curr;
      }

      for (int i = 1; i < k; i++) {
        prev = prev->next;
        last = last->next;
        if (!last) {
          return newhead->next;
        }
      }
    }
    return newhead->next;
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