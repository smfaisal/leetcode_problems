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
  void inord(TreeNode* root, vector<TreeNode*>& err_nodes, TreeNode*& prev, TreeNode*& err_prev) {
    if (!root) {
      return;
    }
    if (!root->left && !root->right) {
      if (prev == NULL) {
        prev = root;
      } else if (prev->val > root->val) {
        err_nodes.push_back(root);
        err_prev = prev;
        if (err_nodes.size() == 2) {
          return;
        }
      }
      prev = root;
      return;
    }

    inord(root->left, err_nodes, prev, err_prev);
//    cout << "Came, root: " << root->val << " prev: " << prev->val << endl;

    if (root->val < prev->val) {
//      cout << "Came" << endl;

      err_nodes.push_back(root);
      err_prev = prev;
      if (err_nodes.size() == 2) {
        return;
      }
    }
    prev = root;
    inord(root->right, err_nodes, prev, err_prev);
  }

  void recoverBST(TreeNode* root) {
    if (!root) {
      return;
    }
    vector<TreeNode* > err_nodes;
    TreeNode* prev = NULL;
    TreeNode* err_prev = NULL;

    inord(root, err_nodes, prev, err_prev);

    int tmp;
    if (err_nodes.size() == 2) {
      tmp = err_nodes[0]->val;
      err_nodes[0]->val = err_nodes[1]->val;
      err_nodes[1]->val = tmp;
    } else if (err_nodes.size() == 1) {
      cout << "Came" << endl;
      tmp = err_nodes[0]->val;
      err_nodes[0]->val = err_prev->val;
      err_prev->val = tmp;
    }
    return;
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