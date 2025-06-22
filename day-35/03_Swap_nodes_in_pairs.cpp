// Leetcode : 24
// Swap Nodes in pairs
// TC : O(n)
// SC : O(1)
#include <iostream>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  ListNode *swapPairs(ListNode *head)
  {
    if (head == NULL || head->next == NULL)
    {
      return head;
    }
    ListNode *first = head;
    ListNode *second = head->next;
    ListNode *prev = NULL;

    while (first != NULL && second != NULL)
    {
      ListNode *third = second->next;
      second->next = first;
      first->next = third;

      if (prev != NULL)
        prev->next = second;
      else
        head = second;
      prev = first;
      first = third;

      if (third != NULL)
        second = third->next;
      else
        second = NULL;
    }
    return head;
  }
};

int main()
{
  // Create linked list: 1->2->3->4
  ListNode *n4 = new ListNode(4);
  ListNode *n3 = new ListNode(3, n4);
  ListNode *n2 = new ListNode(2, n3);
  ListNode *n1 = new ListNode(1, n2);

  Solution sol;
  ListNode *result = sol.swapPairs(n1);

  // Print the swapped list
  ListNode *curr = result;
  while (curr != nullptr)
  {
    cout << curr->val;
    if (curr->next != nullptr)
      cout << "->";
    curr = curr->next;
  }
  cout << endl;

  // Free memory
  curr = result;
  while (curr != nullptr)
  {
    ListNode *temp = curr;
    curr = curr->next;
    delete temp;
  }
  return 0;
}