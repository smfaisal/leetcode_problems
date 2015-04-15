#include <iostream>

using namespace std;

struct TreeLinkNode{
  int val;
  TreeLinkNode *left;
  TreeLinkNode *right;
  TreeLinkNode * next;
  TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution{
public:
  void connect(TreeLinkNode *root) {
    if (!root) {
      return;
    }
    if (root->left) {
      root->left->next = root->right;
    }
    if (root->right) {
      if (root->next) {
        if (root->next->left) {
          root->right->next = root->next->left;
        } else {
          root->right->next = root->next->right;
        }
      }
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