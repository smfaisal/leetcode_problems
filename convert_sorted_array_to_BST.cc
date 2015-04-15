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
  TreeNode* build(vector<int>& num, int st, int end) {
    if (st > end) {
      return NULL;
    }

    int mid = (st+end)/2;
    TreeNode* node = new TreeNode(num[mid]);
    if (st < mid) {
      node->left = build(num, st, mid-1);
    }
    if (mid < end) {
      node->right = build(num, mid+1, end);
    }

    return node;
  }

  TreeNode *sortedArrayToBST(vector<int> &num) {
    if (num.size() == 0) {
      return NULL;
    }

    return build(num, 0, num.size()-1);
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
  int n[] = {10};//, 20, 30, 40, 50};
  vector<int> num(n, n+1);

  TreeNode* root = s.sortedArrayToBST(num);

  cout << "Res: " ;
  inorder_traversal(root);

  cout << endl;
  return 0;
}