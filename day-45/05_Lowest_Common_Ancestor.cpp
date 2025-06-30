// Leetcode : 235
// Lowest Common Ancestor
// TC: O(n)
// in balanced BST => TC: O(logn)
#include <iostream>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
  TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
  {
    if (root == NULL)
      return NULL;

    if (root->val > p->val && root->val > q->val)
      return lowestCommonAncestor(root->left, p, q);

    else if (root->val < p->val && root->val < q->val)
      return lowestCommonAncestor(root->right, p, q);

    else
      return root;
  }
};

int main()
{
  // Example BST:
  //       6
  //      / \
  //     2   8
  //    / \ / \
  //   0  4 7  9
  //     / \
  //    3   5

  TreeNode *root = new TreeNode(6);
  root->left = new TreeNode(2);
  root->right = new TreeNode(8);
  root->left->left = new TreeNode(0);
  root->left->right = new TreeNode(4);
  root->left->right->left = new TreeNode(3);
  root->left->right->right = new TreeNode(5);
  root->right->left = new TreeNode(7);
  root->right->right = new TreeNode(9);

  Solution sol;
  TreeNode *p = root->left;        // Node with value 2
  TreeNode *q = root->left->right; // Node with value 4

  TreeNode *lca = sol.lowestCommonAncestor(root, p, q);
  if (lca)
    cout << "LCA of " << p->val << " and " << q->val << " is " << lca->val << endl;
  else
    cout << "LCA not found." << endl;

  // Clean up memory (not strictly necessary for small test, but good practice)
  delete root->left->right->left;
  delete root->left->right->right;
  delete root->left->left;
  delete root->left->right;
  delete root->right->left;
  delete root->right->right;
  delete root->left;
  delete root->right;
  delete root;

  return 0;
}