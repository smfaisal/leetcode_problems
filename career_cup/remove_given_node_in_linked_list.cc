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
  void deleteNode(ListNode* node) {
    if (!node) {
      return;
    }
    ListNode* next = node->next;
    node->val = node->next->val;
    node->next = node->next->next;
//    delete next;
    return;
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

  ListNode* head = &n1;

  ListNode* cur = head;
  while (cur) {
    cout << cur->val << "->";
    cur = cur->next;
  }
  cout << endl;

  Solution s;
  s.deleteNode(&n3);

  cout << "After delete: " << endl;
  cur = head;
  while (cur) {
    cout << cur->val << "->";
    cur = cur->next;
  }
  cout << endl;
  return 0;
}