#include <iostream>
#include <vector>
#include <cmath>

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

  void getSum(TreeNode* root, int cur, int& sum) {

    if (root->left == NULL && root->right == NULL) {
      cur = cur*10 + root->val;
      //cout << "Sum+= " << cur << endl;
      sum += cur;
    }
    if (root->left) {
      getSum(root->left, cur*10 + root->val, sum);
    }
    if (root->right) {
      getSum(root->right, cur*10 + root->val, sum);
    }
  }

  int sumNumbers(TreeNode *root) {
    int sum = 0;
    int cur = 0;
    if (root) {
      getSum(root, cur, sum);
    }
    return sum;
  }
};

int main() {
  Solution s;
  TreeNode* root = new TreeNode(4);
  root->left = new TreeNode(9);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(0);

  int sum = s.sumNumbers(root);
  cout << "Sum is: " << sum << endl;
  return 0;
}