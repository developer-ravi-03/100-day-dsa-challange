// Leetcode : 662
// Maximum width of binary tree
// TC : O(n)
#include <iostream>
#include <queue>
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
  int widthOfBinaryTree(TreeNode *root)
  {
    queue<pair<TreeNode *, unsigned long long int>> q;
    q.push({root, 0});
    int maxWidth = 0;

    while (q.size() > 0)
    {
      int currLevSize = q.size();
      unsigned long long int stIdx = q.front().second;
      unsigned long long int endIdx = q.back().second;

      maxWidth = max(maxWidth, (int)(endIdx - stIdx + 1));

      for (int i = 0; i < currLevSize; i++)
      {
        auto curr = q.front();
        q.pop();

        if (curr.first->left)
        {
          q.push({curr.first->left, curr.second * 2 + 1});
        }

        if (curr.first->right)
        {
          q.push({curr.first->right, curr.second * 2 + 2});
        }
      }
    }
    return maxWidth;
  }
};

int main()
{
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(3);
  root->right = new TreeNode(2);
  root->left->left = new TreeNode(5);
  root->left->right = new TreeNode(3);
  root->right->right = new TreeNode(9);

  Solution sol;
  int width = sol.widthOfBinaryTree(root);
  cout << "Maximum width of binary tree: " << width << endl;
  return 0;
}