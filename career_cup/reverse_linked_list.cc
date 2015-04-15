#include <iostream>

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int v):val(v), next(NULL) {}
};

class Solution{
public:
  ListNode* reverse(ListNode* head) {
    if (!head) {
      return head;
    }

    ListNode* newhead = new ListNode(0);
    newhead->next = head;
    ListNode* cur = head;
    while (cur->next) {
      cur = cur->next;
    }
    ListNode* tmp;
    while (newhead->next != cur) {
      tmp = newhead->next->next;
      newhead->next->next = cur->next;
      cur->next = newhead->next;
      newhead->next = tmp;
    }

    return newhead->next;
  }
};

int main() {
  Solution s;

  ListNode n1(1);
  ListNode n2(2);
  ListNode n3(3);
  ListNode n4(4);

  n1.next = &n2;
  n2.next = &n3;
  n3.next = &n4;

  ListNode* head = &n1;

  ListNode* cur = head;
  while (cur) {
    cout << cur->val << "->";
    cur = cur->next;
  }
  cout << endl;

  ListNode* newhead = s.reverse(head);

  cur = newhead;
  while (cur) {
    cout << cur->val << "->";
    cur = cur->next;
  }
  cout << endl;
  return 0;
}