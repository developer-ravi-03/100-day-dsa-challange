// Leetcode : 19
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
  ListNode *removeNthFromEnd(ListNode *head, int n)
  {
    ListNode *temp = head;
    int count = 0;
    while (temp != NULL)
    {
      count++;
      temp = temp->next;
    }

    int element = count - n;

    // Yes, you can reuse temp for another loop
    temp = head;
    // Now temp points to head again, and you can use it for further traversal

    // If the node to remove is the head
    if (element == 0)
    {
      ListNode *toDelete = head;
      head = head->next;
      delete toDelete;
      return head;
    }

    // Traverse to the node just before the one to delete
    for (int i = 0; i < element - 1; i++)
    {
      temp = temp->next;
    }

    // Delete the nth node from end
    ListNode *toDelete = temp->next;
    if (toDelete != nullptr)
    {
      temp->next = toDelete->next;
      delete toDelete;
    }
    return head;
  }
};
int main()
{
  // Create a sample linked list: 1->2->3->4->5
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  int n = 2; // Remove 2nd node from end

  Solution sol;
  ListNode *newHead = sol.removeNthFromEnd(head, n);

  // Print the updated list
  ListNode *curr = newHead;
  while (curr != nullptr)
  {
    cout << curr->val << " ";
    curr = curr->next;
  }
  cout << endl;

  // Free memory
  while (newHead != nullptr)
  {
    ListNode *tmp = newHead;
    newHead = newHead->next;
    delete tmp;
  }
  return 0;
}