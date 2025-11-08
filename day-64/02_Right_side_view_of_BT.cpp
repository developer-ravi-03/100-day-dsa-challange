// Leetcode :- 199
//  Right Side  view
#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct TreeNode
{
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val) : val(val), left(nullptr), right(nullptr) {}
};
class Solution
{
public:
  vector<int> rightSideView(TreeNode *root)
  {
    vector<int> ans;
    if (!root)
      return ans;

    queue<TreeNode *> Q;

    Q.push(root);
    while (!Q.empty())
    {
      int size = Q.size();
      int lastval = 0;
      for (int i = 0; i < size; i++)
      {
        TreeNode *curr = Q.front();
        Q.pop();
        lastval = curr->val;
        if (curr->left)
        {
          Q.push(curr->left);
        }
        if (curr->right)
        {
          Q.push(curr->right);
        }
      }
      ans.push_back(lastval);
    }

    return ans;
  }
};
int main()
{
  // Create a binary tree
  TreeNode *root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);
  root->left->left = new TreeNode(4);
  root->left->right = new TreeNode(5);
  root->right->left = new TreeNode(6);
  root->right->right = new TreeNode(7);

  // Create solution object and get bottom view
  Solution solution;
  vector<int> result = solution.rightSideView(root);

  // Print the bottom view
  cout << "Right side view of binary tree: ";
  for (int val : result)
  {
    cout << val << " ";
  }
  cout << endl;
  return 0;
}