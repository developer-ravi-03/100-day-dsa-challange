// Leetcode : 572
// Subtree Tree if another tree
// TC : O(n)
#include <iostream>
using namespace std;
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  bool isIdentical(TreeNode *p, TreeNode *q)
  {

    if (p == NULL || q == NULL)
      return p == q;

    bool isLeftSame = isIdentical(p->left, q->left);
    bool isRightSame = isIdentical(p->right, q->right);

    return isLeftSame && isRightSame && p->val == q->val;
  }

  bool isSubtree(TreeNode *root, TreeNode *subRoot)
  {
    if (root == NULL || subRoot == NULL)
      return root == subRoot;

    if (root->val == subRoot->val && isIdentical(root, subRoot))
      return true;

    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
  }
};

int main()
{
  // Example: root = [1,2,3,4,5], subRoot = [3,4,5]
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->right->left = new TreeNode(4);
  root->right->right = new TreeNode(5);

  TreeNode *subRoot = new TreeNode(3);
  subRoot->left = new TreeNode(4);
  subRoot->right = new TreeNode(5);

  Solution sol;
  if (sol.isSubtree(root, subRoot))
    cout << "subRoot is a subtree of root" << endl;
  else
    cout << "subRoot is NOT a subtree of root" << endl;
  return 0;
}