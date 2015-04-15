#include <iostream>

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left, *right;
  TreeNode(int v):val(v), left(NULL), right(NULL){}
};

void insert(TreeNode*& root, int v) {
  if (!root) {
    root = new TreeNode(v);
    return;
  }
  if (v < root->val) {
    insert(root->left, v);
  } else {
    insert(root->right, v);
  }
}

TreeNode* find(TreeNode* root, int v) {
  if (!root) {
    return NULL;
  }
  if (root->val == v) {
    return root;
  }
  if (root->val > v) {
    return find(root->left, v);
  } else {
    return find(root->right, v);
  }
}

TreeNode* del(TreeNode* root, int v) {
  TreeNode* n = find(root, v);
  if (!n) {
    return root;
  }
  if (!n->left && !n->right) {
    <#statements#>
  }
  TreeNode* x =
}

void inorder(TreeNode* root) {
  if (!root) {
    return;
  }
  inorder(root->left);
  cout << root->val << ", ";
  inorder(root->right);
}

int main() {
  TreeNode* root = NULL;

  insert(root, 15);
  insert(root, 13);
  insert(root, 18);
  insert(root, 5);
  insert(root, 3);
  insert(root, 8);

  inorder(root);

  cout << endl;
  return 0;
}