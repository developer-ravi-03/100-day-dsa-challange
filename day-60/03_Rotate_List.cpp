// Leetcode : 61
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
  ListNode *rotateRight(ListNode *head, int k)
  {
    // if empty list than return
    if (!head)
      return head;

    ListNode *dummy = head;
    int length = 1;

    // find length
    while (dummy->next)
    {
      length++;
      dummy = dummy->next;
    }

    // find posion for more grater k
    int position = k % length;

    // if position is 0 than retun head
    if (position == 0)
      return head;

    // assign curr to just before position
    ListNode *curr = head;
    for (int i = 0; i < length - position - 1; i++)
    {
      curr = curr->next;
    }

    // create new head and connect last node to head and assign curr->next
    // to NULL
    ListNode *newHead = curr->next;
    curr->next = NULL;
    dummy->next = head;
    return newHead;
  }
};
int main()
{
  // Example: Create list 1->2->3->4->5
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  int k = 2;
  Solution sol;
  ListNode *rotated = sol.rotateRight(head, k);

  // Print rotated list
  ListNode *curr = rotated;
  while (curr)
  {
    cout << curr->val << " ";
    curr = curr->next;
  }
  cout << endl;

  // Free memory
  curr = rotated;
  while (curr)
  {
    ListNode *temp = curr;
    curr = curr->next;
    delete temp;
  }

  return 0;
}