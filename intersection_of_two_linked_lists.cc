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
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (!headA || !headB) {
      return NULL;
    }
    int a_len = 0;
    int b_len = 0;

    ListNode* cur_a = headA;
    ListNode* cur_b = headB;

    while (cur_a) {
      a_len++;
      cur_a = cur_a->next;
    }

    while (cur_b) {
      b_len++;
      cur_b = cur_b->next;
    }

    int diff = abs(a_len-b_len);

    cur_a = headA;
    cur_b = headB;

    if (diff > 0) {
      if (a_len > b_len) {
        for (int i = 0; i < diff; i++) {
          cur_a = cur_a->next;
        }
      } else {
        for (int i = 0; i < diff; i++) {
          cur_b = cur_b->next;
        }
      }
    }
    while (cur_a) {
      if (cur_a == cur_b) {
        return cur_a;
      }
      cur_a = cur_a->next;
      cur_b = cur_b->next;
    }
    return NULL;
  }
};

int main() {
  ListNode n1(1);
  ListNode n2(2);
  ListNode n3(3);
  ListNode n4(4);
  ListNode n5(5);
  ListNode* headA = &n1;
  n1.next = &n2;
  n2.next = &n3;
  n3.next = &n4;
  n4.next = &n5;

//  ListNode nb1(1);
//  ListNode nb2(2);
//  ListNode nb3(3);
//  ListNode nb4(4);
//  ListNode nb5(5);
  ListNode* headB = &n4;
//  nb1.next = &nb2;
//  nb2.next = &nb3;
//  nb3.next = &nb4;
//  nb4.next = &nb5;

  Solution s;

  ListNode* intersect = s.getIntersectionNode(headA, headB);

  if (intersect) {
    cout << "Intersects at: " << intersect->val << endl;
  } else {
    cout << "No intersect" << endl;
  }


  return 0;
}