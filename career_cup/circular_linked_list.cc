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

class Solution{
public:
  ListNode* circle(ListNode* head) {
    if (!head || !(head->next)) {
      return NULL;
    }
    ListNode* tort = head;
    ListNode* hare = head->next;

    while (tort != hare) {
      tort = tort->next;
      if (hare->next) {
        hare = hare->next->next;
      } else {
        return NULL;
      }
    }

    tort = head;
    hare = hare->next;

    while (tort != hare) {
      cout << "Tort: " << tort->val << " Hare: " << hare->val << endl;

      tort = tort->next;
      hare = hare->next;
    }
    return tort;
  }
};

int main() {
  ListNode n1(1);
  ListNode n2(2);
  ListNode n3(3);
  ListNode n4(4);
  ListNode n5(5);
  ListNode n6(6);

  n1.next = &n2;
  n2.next = &n3;
  n3.next = &n4;
  n4.next = &n5;
  n5.next = &n6;
  n6.next = &n4;

  Solution s;
  ListNode* loop = s.circle(&n1);

  cout << "Loop at node: " << loop->val << endl;
  return 0;
}