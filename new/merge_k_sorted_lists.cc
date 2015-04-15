#include <iostream>
#include <vector>
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

class Solution{
public:
  struct mycomp{
    bool operator()(ListNode* a, ListNode* b) const {
      return a->val > b->val;
    }
  };

  ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.size() == 0) {
      return NULL;
    }
    ListNode* reshead = new ListNode(0);
    ListNode* cur_res = reshead;
    vector<ListNode* > curs;
    for (int i = 0; i < lists.size(); i++) {
      if (lists[i]) {
        curs.push_back(lists[i]);
      }
    }

    priority_queue<ListNode*, vector<ListNode* >, mycomp> pq(curs.begin(), curs.end());

    ListNode* t;
    while (!pq.empty()) {
      t = pq.top()->next;
      cur_res->next = pq.top();
      cur_res = cur_res->next;
      pq.pop();
      if (t) {
        pq.push(t);
      }
    }
    return reshead->next;
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