#include <iostream>

using namespace std;

struct node {
  struct node *left,*right;
  int val;
};

int longest_path(node* root) {
  if (!root) {
    return 0;
  }
  return max(longest_path(root->left), longest_path(root->right))+1;
}

/* Write your custom functions here */
int diameterOfTree(node * root) {
  /* For your reference
   struct node {
   struct node *left,*right;
   int val;
   };
   */
  if (!root) {
    return 0;
  }
  int llongest = longest_path(root->left);
  int rlongest = longest_path(root->right);
  int thru = llongest+rlongest;

  if (root->left || root->right) {
    thru += 1;
  }

  int ldia = diameterOfTree(root->left);
  int rdia = diameterOfTree(root->right);

  return max(thru, max(ldia, rdia));
}

int main() {
  node n1, n2, n3, n4, n5, n6;
  n1.val = 40;
  n2.val = 30;
  n3.val = 22;
  n4.val = 38;
  n5.val = 65;
  n6.val = 78;
  n1.left = &n2;
  n1.right = &n5;
  n2.left = &n3;
  n2.right = &n4;
  n3.left = n3.right = NULL;
  n4.left = n4.right = NULL;
  n5.left = &n6;
  n5.right = n6.left = n6.right = NULL;

  cout << "diameter: " << diameterOfTree(&n1) << endl;
  return 0;
}
