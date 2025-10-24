// Leetcode : 144
#include <iostream>
#include <vector>
using namespace std;
struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
                                                     right(right) {}
};

class Solution
{
public:
  // helper function
  void preOrder(TreeNode *node, vector<int> &res)
  {
    if (node == NULL)
      return;
    res.push_back(node->val);
    preOrder(node->left, res);
    preOrder(node->right, res);
  }
  vector<int> preorderTraversal(TreeNode *root)
  {
    vector<int> res;
    preOrder(root, res);
    return res;
  }
};

int main()
{
  // Create a sample binary tree
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);

  Solution solution;
  vector<int> result = solution.preorderTraversal(root);

  // Print the result
  cout << "Preorder traversal: ";
  for (int val : result)
  {
    cout << val << " ";
  }
  cout << endl;

  // Clean up memory
  delete root->left->right;
  delete root->left->left;
  delete root->left;
  delete root->right;
  delete root;
  return 0;
}