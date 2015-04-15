#include <iostream>
#include <unordered_map>

using namespace std;

// Definition for singly-linked list with a random pointer.
struct RandomListNode {
	int label;
	RandomListNode *next, *random;
	RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

class Solution {
 public:
  RandomListNode *copyRandomList(RandomListNode *head) {
    unordered_map<RandomListNode*, RandomListNode*> map;
    RandomListNode* start = head;
    RandomListNode* new_head = NULL;
    RandomListNode* new_start = NULL;

    if (head == NULL) {
      return new_head;
    }

    new_head = new RandomListNode(start->label);
    new_head->random = start->random;

    map[head] = new_head;
    new_start = new_head;

    while (start->next != NULL) {
      new_start->next = new RandomListNode(start->next->label);
      new_start->next->random = start->next->random;
      map[start->next] = new_start->next;
      start = start->next;
      new_start = new_start->next;
    }
    new_start->next = NULL;

    // Now fill out the random pointers.
    new_start = new_head;
    while (new_start) {
      if (new_start->random) {
        new_start->random = map[new_start->random];
      }
      new_start = new_start->next;
    }
    return new_head;
  }
};
