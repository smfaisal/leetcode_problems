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
    root->left->next = root->right;
    if (root->next) {
      root->right->next = root->next->left;
    }
    connect(root->left);
    connect(root->right);
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