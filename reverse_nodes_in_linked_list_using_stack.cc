#include <iostream>
#include <stack>

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
  ListNode* reverse(ListNode* head) {
    ListNode* curr = head;
    stack<ListNode* > nodes;

    while (curr) {
      nodes.push(curr);
      curr = curr->next;
    }
    if (!nodes.empty()) {
      head = nodes.top();
    }

    curr = nodes.top();

    while (curr) {
      nodes.pop();
      if (!nodes.empty()) {
        curr->next = nodes.top();
        curr = nodes.top();
      } else {
        curr->next = NULL;
        curr = NULL;
      }
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
  head = s.reverse(head);

  curr = head;
  while (curr) {
    cout << curr->val << "->";
    curr = curr->next;
  }

  cout << endl;

  return 0;
}