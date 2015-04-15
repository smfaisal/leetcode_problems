#include <iostream>
#include <vector>

using namespace std;

// Definition for binary tree
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
public:
  void inord(TreeNode* root, vector<TreeNode*>& swapped, TreeNode*& prev, TreeNode*& err_parent) {
    if (!root) {
      return;
    }
    if (!root->left && !root->right) {
      if (prev) {
        cout << "prev: " << prev->val << " root: " << root->val << endl;
        if (prev->val > root->val) {
          swapped.push_back(root);
          if (!err_parent) {
            err_parent = prev;
          }
          if (swapped.size() == 2) {
            return;
          }
        }
      }
      prev = root;
      return;
    }
    inord(root->left, swapped, prev, err_parent);
    cout << "prev: " << prev->val << " root: " << root->val << endl;
    if (prev->val > root->val) {
      swapped.push_back(root);
      if (!err_parent) {
        err_parent = prev;
      }
      if (swapped.size() == 2) {
        return;
      }
    }
    prev = root;
    inord(root->right, swapped, prev, err_parent);
  }

  void recoverBST(TreeNode* root) {
    if (!root) {
      return;
    }
    vector<TreeNode*> swapped;
    TreeNode* prev = NULL;
    TreeNode* err_parent = NULL;

    int tmp;
    inord(root, swapped, prev, err_parent);
    cout << swapped.size() << endl;

    if (swapped.size() == 2) {
      tmp = swapped[0]->val;
      swapped[0]->val = swapped[1]->val;
      swapped[1]->val = tmp;
    } else {
      tmp = err_parent->val;
      err_parent->val = swapped[0]->val;
      swapped[0]->val = tmp;
    }
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
  TreeNode* root = new TreeNode(3);
  root->left = new TreeNode(2);
  root->right = new TreeNode(7);
  root->left->left = new TreeNode(1);
  root->left->right = new TreeNode(4);

  cout << "Before: " << endl;
  inorder_traversal(root);
  cout << endl;

  s.recoverBST(root);

  cout << "after: " << endl;
  inorder_traversal(root);
  cout << endl;

  return 0;
}