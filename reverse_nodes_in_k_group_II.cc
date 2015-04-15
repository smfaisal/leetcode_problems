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
    if (k < 2 || !head) {
      return head;
    }

    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* next = NULL;
    ListNode* scurr;

    stack<ListNode* > nodes;

    while (curr) {
      for (int i = 1; i <= k; i++) {
        nodes.push(curr);
        curr = curr->next;
        if (!curr) {
          break;
        }
      }

      if (nodes.size() < k) {
        break;
      }

      if (prev) {
        prev->next = nodes.top();
      } else {
        head = nodes.top();
      }

      scurr = nodes.top();
      while (scurr) {
        nodes.pop();
        if (!nodes.empty()) {
          scurr->next = nodes.top();
          scurr = nodes.top();
        } else {
          scurr->next = curr;
          prev = scurr;
          scurr = NULL;
        }
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
  head = s.reverseKGroup(head, 3);

  curr = head;
  while (curr) {
    cout << curr->val << "->";
    curr = curr->next;
  }

  cout << endl;

  return 0;
}