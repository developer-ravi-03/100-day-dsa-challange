// Leetcode : 108
// Convert Sorted array in balanced BST
// TC : O(n)
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
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
  TreeNode *helper(vector<int> &nums, int st, int end)
  {
    if (st > end)
      return NULL;

    int mid = st + (end - st) / 2;
    TreeNode *root = new TreeNode(nums[mid]);

    root->left = helper(nums, st, mid - 1);
    root->right = helper(nums, mid + 1, end);

    return root;
  }

  TreeNode *sortedArrayToBST(vector<int> &nums)
  {
    int st = 0, end = nums.size() - 1;
    return helper(nums, st, end);
  }
};

void inoder(TreeNode *root)
{
  if (root == nullptr)
    return;
  inoder(root->left);
  cout << root->val << " ";
  inoder(root->right);
}

int main()
{
  vector<int> nums = {-10, -3, 0, 5, 9};
  Solution sol;
  TreeNode *root = sol.sortedArrayToBST(nums);
  inoder(root);
  cout << endl;
  return 0;
}