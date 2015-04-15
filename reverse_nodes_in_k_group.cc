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
	ListNode* reverseList(ListNode* st, ListNode* end) {
		ListNode* node = st;
		ListNode* temp;
		if (st == end) {
			return end;
		}
		reverseList(st->next, end);
		temp = st->next->next;
		st->next->next = st;
		st->next = temp;
		return end;
	}

  ListNode *reverseKGroup(ListNode *head, int k) {   
		bool first = true;
		ListNode* start = head;
		ListNode* end;
		ListNode* prev;
		while(true) {
						if (!start) {
										return head;
						}
						end = start;
						// cout << "St: " << start->val;
						for (int i = 1; i < k; i++) {
							if (!end->next) {
								return head;
							}
							end = end->next;
						}
						// cout << " end: " << end->val;
						if (first) {
								head = reverseList(start, end);
								first = false;
						} else {
							prev->next = reverseList(start, end);
						}
						prev = start;
						start = start->next;
		}
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
	while (head) {
		cout << head->val << " -> ";
		head = head->next;
	}
	cout << endl;
	// s.reverseList(&n1, &n5);
	
	head = s.reverseKGroup(&n1, 1);
	while (head) {
		cout << head->val << " -> ";
		head = head->next;
	}
	cout << endl;
}
