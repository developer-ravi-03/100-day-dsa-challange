// Binary tree Level Order Traversal
// Leetcode : 102
#include <iostream>
#include <vector>
#include <queue>
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
  vector<vector<int>> levelOrder(TreeNode *root)
  {
    vector<vector<int>> ans;

    if (root == nullptr) // handle empty tree
      return ans;

    queue<TreeNode *> Q;
    Q.push(root);
    while (Q.size() > 0)
    {
      int levelSize = Q.size();
      vector<int> level;
      for (int i = 0; i < levelSize; ++i)
      {
        TreeNode *curr = Q.front();
        Q.pop();
        level.push_back(curr->val);

        if (curr->left != NULL)
        {
          Q.push(curr->left);
        }

        if (curr->right != NULL)
        {
          Q.push(curr->right);
        }
      }

      ans.push_back(level);
    }

    return ans;
  }
};

int main()
{
  Solution solution;
  // Create a sample binary tree
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);

  // Get level order traversal
  vector<vector<int>> result = solution.levelOrder(root);

  // Print the result
  for (const auto &level : result)
  {
    for (int val : level)
    {
      cout << val << " ";
    }
    cout << endl;
  }

  // Clean up memory
  delete root->right->right;
  delete root->right->left;
  delete root->right;
  delete root->left;
  delete root;
  return 0;
}