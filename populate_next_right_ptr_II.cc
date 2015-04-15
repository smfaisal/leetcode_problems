#include <iostream>

using namespace std;

// Definition for binary tree
struct TreeLinkNode {
  int val;
  TreeLinkNode *left;
  TreeLinkNode *right;
  TreeLinkNode * next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:

  void connect(TreeLinkNode *root) {
    if (!root || (!root->left && !root->right)) {
      return;
    }
    // Go top down
    if (root->right) {
      if (root->left)
        root->left->next = root->right;
      TreeLinkNode* n = root->next;
      while (n) {
        if (n->left) {
          root->right->next = n->left;
          break;
        } else if (n->right) {
          root->right->next = n->right;
          break;
        }
        n = n->next;
      }
    } else if (root->left && root->next) {
      TreeLinkNode* n = root->next;
      while (n) {
        if (n->left) {
          root->left->next = n->left;
          break;
        } else if (n->right) {
          root->left->next = n->right;
          break;
        }
        n = n->next;
      }
    }
    connect(root->right);
    connect(root->left);
  }
};

int main() {
  Solution s;
  TreeLinkNode* root = new TreeLinkNode(1);
  root->left = new TreeLinkNode(2);
  root->right = new TreeLinkNode(3);
  //  root->left->left = new TreeLinkNode(0);

  //int sum = s.sumNumbers(root);
  //cout << "Sum is: " << sum << endl;
  s.connect(root);
  return 0;
}