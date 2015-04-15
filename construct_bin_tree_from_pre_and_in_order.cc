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

class Solution {
public:
  TreeNode* getTree(vector<int> &preorder, int pre_st, int pre_end, vector<int> &inorder, int in_st, int in_end) {
    if (pre_st > pre_end) {
      return NULL;
    }

    TreeNode* node = new TreeNode(preorder[pre_st]);

    int root_in_inorder = in_st;

    while (inorder[root_in_inorder] != preorder[pre_st]) {
      root_in_inorder++;
    }
    int left_subtree_len = root_in_inorder-in_st;
    int right_subtree_len = in_end-root_in_inorder;
    if (left_subtree_len > 0) {
      node->left = getTree(preorder, pre_st+1, pre_st+left_subtree_len, inorder, in_st, root_in_inorder-1);
    }
    if (right_subtree_len > 0) {
      node->right = getTree(preorder, pre_st+left_subtree_len+1, pre_end, inorder, root_in_inorder+1, in_end);
    }

    return node;
  }

  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.size() == 0) {
      return NULL;
    }
    int len = preorder.size();
    return getTree(preorder, 0, len-1, inorder, 0, len-1);
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
  TreeNode* root; // = new TreeNode(3);
//  root->left = new TreeNode(2);
//  root->right = new TreeNode(7);
//  root->left->left = new TreeNode(1);
//  root->left->right = new TreeNode(4);

  int inord[] = {1, 2, 3, 4, 5};
  vector<int> inorder(inord, inord+5);
  int preord[] = {1, 2, 3, 4, 5};
  vector<int> preorder(preord, preord+5);

  root = s.buildTree(preorder, inorder);

  cout << "Res: " ;
  inorder_traversal(root);

  cout << endl;
  return 0;
}