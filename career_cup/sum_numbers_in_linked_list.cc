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
  ListNode* add(ListNode* h1, ListNode* h2) {
    if (!h1 && !h2) {
      return NULL;
    } else if (!h1) {
      return h2;
    } else if (!h2) {
      return h1;
    }
    ListNode* res = new ListNode(0);
    ListNode* res_head = res;
    int carry = 0;
    int n = 0;
    while (h1 && h2) {
      n = h1->val + h2->val + carry;
      carry = n/10;
      n = n%10;
      res->next = new ListNode(n);
      res = res->next;
      h1 = h1->next;
      h2 = h2->next;
    }

    if (!h1 || !h2) {
      if (!h1) {
        while (h2) {
          n = h2->val + carry;
          carry = n/10;
          n = n%10;
          res->next = new ListNode(n);
          res = res->next;
          h2 = h2->next;
        }
      } else {
        while (h1) {
          n = h1->val + carry;
          carry = n/10;
          n = n%10;
          res->next = new ListNode(n);
          res = res->next;
          h1 = h1->next;
        }
      }
    }
    if (carry) {
      res->next = new ListNode(carry);
    }
    return res_head->next;
  }
};

int main() {
  ListNode n1(8);
  ListNode n2(2);
  ListNode n3(3);
  ListNode n4(4);
  ListNode n5(5);
  ListNode n6(6);

  n1.next = &n2;
  n2.next = &n3;
//  n3.next = &n4;
  n4.next = &n5;
  n5.next = &n6;

  ListNode* h1 = &n1;
  ListNode* h2 = &n4;

  Solution s;

  ListNode* res = s.add(h1, h2);

  ListNode* cur = res;

  cout << "Res: " << endl;
  while (cur) {
    cout << cur->val << "->";
    cur = cur->next;
  }
  cout << endl;
  return 0;
}