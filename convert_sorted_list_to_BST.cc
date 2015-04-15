#include <iostream>
#include <vector>

using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode*	next;
  ListNode(int x) : val(x), next(NULL) {}
};

// Definition for binary tree
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
  int findLen(ListNode* head) {
    int len = 0;
    while (head) {
      head = head->next;
      len++;
    }
    return len;
  }
  TreeNode* buildTree(ListNode* head, int len) {
    if (len <= 0) {
      return NULL;
    }
    int mid = len/2;
    ListNode* mid_node = head;
    for (int i = 0; i < mid; i++) {
      mid_node = mid_node->next;
    }

    TreeNode* node = new TreeNode(mid_node->val);

    node->left = buildTree(head, mid);
    node->right = buildTree(mid_node->next, len-mid-1);

    return node;
  }

  TreeNode *sortedListToBST(ListNode *head) {
    if (!head) {
      return NULL;
    }
    int len = findLen(head);
    return buildTree(head, len);
  }
};

void inorder_traversal(TreeNode* root) {
  if (!root) {
    return;
  }
  inorder_traversal(root->left);
  cout << root->val << ", ";
  inorder_traversal(root->right);
}

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

  TreeNode* root = s.sortedListToBST(&n1);

  inorder_traversal(root);
  cout << endl;
  return 0;
}