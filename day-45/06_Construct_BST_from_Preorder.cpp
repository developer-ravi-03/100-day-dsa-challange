// Leetcode : 1008
// Construct BST From Preorder
// TC: O(n)
#include <iostream>
#include <vector>
#include <climits>
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
  TreeNode *helper(vector<int> &preorder, int &i, int bound)
  {
    if (i >= preorder.size() || preorder[i] > bound)
      return NULL;

    TreeNode *root = new TreeNode(preorder[i]);
    i++;

    root->left = helper(preorder, i, root->val);
    root->right = helper(preorder, i, bound);

    return root;
  }

  TreeNode *bstFromPreorder(vector<int> &preorder)
  {
    int i = 0;
    return helper(preorder, i, INT_MAX);
  }
};

int inorder(TreeNode *root)
{
  if (!root)
    return 0;
  inorder(root->left);
  cout << root->val << " ";
  inorder(root->right);
  return 0;
}

int main()
{
  vector<int> preorder = {6, 3, 1, 4, 8, 9};
  Solution sol;
  TreeNode *root = sol.bstFromPreorder(preorder);
  inorder(root);
  cout << endl;
  return 0;
}