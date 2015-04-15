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
  ListNode *detectCycle(ListNode *head) {
    if (!head || head->next == NULL) {
      return NULL;
    }
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast) {
      if (fast == slow) {
        break;
      }
      else {
        slow = slow->next;
        if (fast->next == NULL) {
          return NULL;
        } else {
          fast = fast->next->next;
        }
      }
    }
    if (!fast) {
      return NULL;
    } else {
      slow = head;
      fast = fast->next;
      while (fast != slow) {
        slow = slow->next;
        fast = fast->next;
      }
      return slow;
    }
  }
};

int main() {
  ListNode n1(1);
  ListNode n2(2);
  ListNode* head = &n1;
  n1.next = &n2;

  Solution s;

  cout << "Cycle? " << s.detectCycle(head) << endl;
}