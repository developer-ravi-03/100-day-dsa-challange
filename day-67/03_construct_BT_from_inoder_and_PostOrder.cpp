#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
  int data;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution
{
public:
  int search(vector<int> &inorder, int left, int right, int tar)
  {
    for (int i = left; i <= right; i++)
    {
      if (inorder[i] == tar)
        return i;
    }
    return -1;
  }

  TreeNode *helper(vector<int> &inorder, vector<int> &postorder, int &postIdx,
                   int left, int right)
  {

    if (left > right)
      return NULL;

    TreeNode *root = new TreeNode(postorder[postIdx]);

    int inIdx = search(inorder, left, right, postorder[postIdx]);
    postIdx--;

    root->right = helper(inorder, postorder, postIdx, inIdx + 1, right);
    root->left = helper(inorder, postorder, postIdx, left, inIdx - 1);

    return root;
  }

  TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
  {
    int postIdx = inorder.size() - 1;
    int left = 0;
    int right = inorder.size() - 1;
    return helper(inorder, postorder, postIdx, left, right);
  }
};

int main()
{

  vector<int> inorder = {9, 3, 15, 20, 7};
  vector<int> postorder = {9, 15, 7, 20, 3};

  Solution sol;
  TreeNode *root = sol.buildTree(inorder, postorder);

  // Print tree (level-order traversal)
  if (root)
  {
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
      TreeNode *node = q.front();
      q.pop();
      cout << node->data << " ";
      if (node->left)
        q.push(node->left);
      if (node->right)
        q.push(node->right);
    }
    cout << endl;
  }

  return 0;
}