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
  bool hasCycle(ListNode *head) {
    if (!head || head->next == NULL) {
      return false;
    }
    ListNode* slow = head;
    ListNode* fast = head->next;
    while (fast) {
      if (fast == slow) {
        return true;
      }
      else {
        slow = slow->next;
        if (fast->next == NULL) {
          return false;
        } else {
          fast = fast->next->next;
        }
      }
    }
  }
};

int main() {
  ListNode n1(1);
  ListNode n2(2);
  ListNode* head = &n1;
  n1.next = &n2;

  Solution s;

  cout << "Cycle? " << s.hasCycle(head) << endl;
}