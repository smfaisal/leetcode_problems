#include <iostream>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
	int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
  public:
  void reverse(ListNode** head) {
    ListNode* prev = *head;
    ListNode* cur = (*head)->next;
    ListNode* next = cur->next;
    if (prev == NULL || cur == NULL) {
      return;
    }

    while (cur) {
      next = cur->next;
      cur->next = prev;
      prev = cur;
      cur = next;
    }
    (*head)->next = NULL;
    *head = prev;
  }

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

  void stitch(ListNode* l1, ListNode* l2) {
    ListNode* tmp;
    if (!l1 || !l2) {
      return;
    }
    while (l1->next) {
      tmp = l1->next;
      l1->next = l2;
      l1 = tmp;
      tmp = l2->next;
      l2->next = l1;
      l2 = tmp;
    }
    l1->next = l2;
  }

  void reorderList(ListNode *head) {
    ListNode* left;
    ListNode* right;
    if (!head || !(head->next) || !(head->next->next)) {
      return;
    }
    split(head, &left, &right);
    reverse(&right);
    stitch(left, right);
  }
};

int main() {
	Solution s;
	ListNode n1(1), n2(2), n3(3), n4(4), n5(5);
	n1.next = &n2;
	n2.next = &n3;
	n3.next = &n4;
	n4.next = &n5;

	ListNode* head = &n1;
  s.reorderList(head);
	while (head) {
		cout << head->val << " -> ";
		head = head->next;
	}
	cout << endl;
  return 0;
}