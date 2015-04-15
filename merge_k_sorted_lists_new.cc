#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

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
  typedef bool (*comp)(ListNode* a, ListNode* b);
  static bool mycomp(ListNode* a, ListNode* b) {
    return a->val > b->val;
  }
  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.size() == 0) {
      return NULL;
    } else if (lists.size() == 1) {
      return lists[0];
    }

    ListNode* head, *curr;
//    unordered_set<ListNode* > curr_heads;
    priority_queue<ListNode*, vector<ListNode*>, comp> curr_heads(mycomp);
    for (int i = 0; i < lists.size(); i++) {
      if (lists[i]) {
        curr_heads.push(lists[i]);
      }
    }

    if (curr_heads.size() == 0) {
      return NULL;
    }

    curr = curr_heads.top();
    curr_heads.pop();
    if (curr->next) {
      curr_heads.push(curr->next);
    }
    head = curr;
//    curr = head;
    ListNode* t;
    while (curr_heads.size() > 1) {
      curr->next = curr_heads.top();
      t = curr_heads.top();
      curr_heads.pop();
      if (t->next) {
        curr_heads.push(t->next);
      }
      curr = curr->next;
    }
    if (curr_heads.size()) {
      curr->next = curr_heads.top();
      curr_heads.pop();
    }
    return head;
  }
};

int main() {
  ListNode n1(10);
  ListNode n2(40);
  ListNode n3(50);
  ListNode n4(45);
  ListNode n5(54);
  ListNode n6(63);
  ListNode n7(71);

  n1.next = &n2;
  n2.next = &n3;
  n4.next = &n5;
  n6.next = &n7;

  ListNode* head1 = &n1;
  ListNode* head2 = &n4;
  ListNode* head3 = &n6;

  vector<ListNode* > lists;
  lists.push_back(head1);
  lists.push_back(head2);
  lists.push_back(head3);

  Solution s;
  ListNode* head = s.mergeKLists(lists);

  ListNode* curr = head;

  while (curr) {
    cout << curr->val << "->";
    curr = curr->next;
  }
  cout << endl;

  return 0;
}

