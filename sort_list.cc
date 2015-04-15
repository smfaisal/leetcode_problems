#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode*	next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  void split (ListNode* start, ListNode** aref, ListNode** bref) {
    ListNode* fast = start;
    ListNode* slow = start;
    while (true) {
      if (fast->next != NULL) {
        fast = fast->next->next;
      }
      if (fast == NULL || fast->next == NULL) {
        break;
      }
      slow = slow->next;
    }
    *aref = start;
    *bref = slow->next;
    slow->next = NULL;
  }

  ListNode* mergeSortedList (ListNode* list1, ListNode* list2) {
    ListNode* head = new ListNode(0);
    ListNode* newhead = head;
    while (list1 && list2) {
      if (list1->val <= list2->val) {
        newhead->next = list1;
        list1 = list1->next;
      } else {
        newhead->next = list2;
        list2 = list2->next;
      }
      newhead = newhead->next;
    }
    if (!list1) {
      newhead->next = list2;
    } else {
      newhead->next = list1;
    }
    return head->next;
  }

  void sort (ListNode** head) {
    ListNode* start = *head;
    if (start == NULL || start->next == NULL) {
      return;
    }
    ListNode* left;
    ListNode* right;
    split(start, &left, &right);

    sort(&left);
    sort(&right);
    *head = mergeSortedList(left, right);
  }

  ListNode *sortList (ListNode *head) {
    sort(&head);
    return head;
  }
};

int main() {
  Solution s;
  ListNode n1(1), n2(2), n3(3), n4(4), n5(5);
  n5.next = &n2;
  n2.next = &n4;
  n4.next = &n3;
  n3.next = &n1;

  ListNode* head = &n5;

  while (head) {
    cout << head->val << " -> ";
    head = head->next;
  }
  cout << endl;

  ListNode* sorted = s.sortList(&n5);
  head = sorted;
  while (head) {
    cout << head->val << " -> ";
    head = head->next;
  }
  cout << endl;

  return 0;
}
