#include <iostream>

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
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    // IMPORTANT: Please reset any member data you declared, as
    // the same Solution instance will be reused for each test case.
    if(!l1){
      return l2;
    }
    if(!l2){
      return l1;
    }

    ListNode * head = new ListNode(0);
    bool first = true;
    int sum = 0;
    int carry = 0;
    ListNode * cur = head;

    while(l1 && l2){
      sum = (l1->val + l2->val + carry)%10;
      carry = (l1->val+l2->val + carry)/10;

      if(first){
        head->val = sum;
        first = false;
      }
      else{
        ListNode * newLN = new ListNode(sum);
        cur->next = newLN;
        cur = newLN;
      }
      l1 = l1->next;
      l2 = l2->next;
    }
    ListNode * tmp = (l1)?l1:l2;
    while(tmp){
      sum = (tmp->val + carry)%10;
      carry = (tmp->val+carry)/10;
      ListNode * newLN = new ListNode(sum);
      cur->next = newLN;
      cur = newLN;
      tmp = tmp->next;
    }
    if(carry){
      ListNode * newLN = new ListNode(carry);
      cur->next = newLN;
      cur = newLN;
    }
    return head;
  }
};
