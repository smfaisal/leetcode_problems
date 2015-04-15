#include <iostream>
#include <stack>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
  ListNode *reverseKGroup(ListNode *head, int k) {
    if (!head) {
      return head;
    }
    ListNode* curr = head;
    int i;
    stack<ListNode* > stk;
    for ( i = 1; i <= k; i++) {
      stk.push(curr);
      curr = curr->next;
      if (!curr) {
        break;
      }
    }

    if (i < k) {
      return head;
    }

    head = stk.top();
    ListNode* c = head;
    stk.pop();
    while (stk.size() > 0) {
      c->next = stk.top();
      stk.pop();
      c = c->next;
    }
//    c = c->next;

    c->next = reverseKGroup(curr, k);
    return head;
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