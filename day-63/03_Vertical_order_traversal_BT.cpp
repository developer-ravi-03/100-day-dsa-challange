// Leetcode - 987
#include <bits/stdc++.h>
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
  vector<vector<int>> verticalTraversal(TreeNode *root)
  {
    map<int, map<int, multiset<int>>> mp;
    queue<pair<TreeNode *, pair<int, int>>> todo;
    todo.push({root, {0, 0}});
    while (!todo.empty())
    {
      auto p = todo.front();
      todo.pop();
      TreeNode *node = p.first;
      int x = p.second.first, y = p.second.second;

      mp[x][y].insert(node->val);

      if (node->left)
      {
        todo.push({node->left, {x - 1, y + 1}});
      }

      if (node->right)
      {
        todo.push({node->right, {x + 1, y + 1}});
      }
    }

    vector<vector<int>> ans;
    for (auto p : mp)
    {
      vector<int> col;
      for (auto q : p.second)
      {
        // it works like maintain the order
        col.insert(col.end(), q.second.begin(), q.second.end());
      }
      ans.push_back(col);
    }
    return ans;
  }
};
int main()
{
  // Create a sample binary tree
  TreeNode *root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);

  Solution solution;
  vector<vector<int>> result = solution.verticalTraversal(root);

  // Print the result
  for (const auto &col : result)
  {
    for (int val : col)
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
