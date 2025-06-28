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
    if (root == p || root == q)
      return root;

    TreeNode *leftLCA = lowestCommonAncestor(root->left, p, q);
    TreeNode *rightLCA = lowestCommonAncestor(root->right, p, q);

    if (leftLCA && rightLCA)
      return root;
    else if (leftLCA != NULL)
      return leftLCA;
    else
      return rightLCA;
  }
};

int main()
{
  // Construct the binary tree
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(5);
  root->right = new TreeNode(1);
  root->left->left = new TreeNode(6);
  root->left->right = new TreeNode(2);
  root->right->left = new TreeNode(0);
  root->right->right = new TreeNode(8);
  root->left->right->left = new TreeNode(7);
  root->left->right->right = new TreeNode(4);

  TreeNode *p = root->left;               // Node with value 5
  TreeNode *q = root->left->right->right; // Node with value 4

  Solution sol;
  TreeNode *lca = sol.lowestCommonAncestor(root, p, q);

  if (lca)
    cout << "Lowest Common Ancestor: " << lca->val << endl;
  else
    cout << "Lowest Common Ancestor not found." << endl;
  return 0;
}