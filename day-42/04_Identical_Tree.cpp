// Leetcode : 100
// Same Tree
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
  bool isSameTree(TreeNode *p, TreeNode *q)
  {

    if (p == NULL || q == NULL)
      return p == q;

    bool isLeftSame = isSameTree(p->left, q->left);
    bool isRightSame = isSameTree(p->right, q->right);

    return isLeftSame && isRightSame && p->val == q->val;
  }
};

int main()
{
  TreeNode *root1 = new TreeNode(1, new TreeNode(2), new TreeNode(3));
  TreeNode *root2 = new TreeNode(1, new TreeNode(3), new TreeNode(3));

  Solution sol;
  if (sol.isSameTree(root1, root2))
    cout << "The trees are identical." << endl;
  else
    cout << "The trees are not identical." << endl;
  return 0;
}