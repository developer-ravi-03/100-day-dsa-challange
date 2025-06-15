
// Problem: Remove a cycle from a linked list if it exists
// Slow and Fast Approach
// TC: O(n)
// SC: O(1)
#include <iostream>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
  ListNode *detectCycle(ListNode *head)
  {
    ListNode *slow = head;
    ListNode *fast = head;
    bool isCycle = false;

    while (fast != NULL && fast->next != NULL)
    {
      slow = slow->next;
      fast = fast->next->next;
      if (slow == fast)
      {
        isCycle = true;
        break;
      }
    }

    if (!isCycle)
    {
      return NULL;
    }

    slow = head;
    ListNode *prev = NULL; // To keep track of the previous node
    while (slow != fast)
    {
      slow = slow->next;
      prev = fast; // Update previous node with the fast pointer
      fast = fast->next;
    }
    // To remove the cycle, set the next of the last node in the cycle to NULL
    if (prev != NULL) // Check if prev is not null to avoid dereferencing a null pointer
    {
      prev->next = NULL; // Break the cycle
    }
    return slow;
  }
};
int main()
{
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  // Creating a cycle for testing
  head->next->next->next->next->next = head->next->next; // 5 points to 3

  Solution sl;
  ListNode *cycleStart = sl.detectCycle(head);
  if (cycleStart)
  {
    cout << "The linked list has a cycle starting at node with value: " << cycleStart->val << endl;
  }
  else
  {
    cout << "The linked list does not have a cycle." << endl;
  }
  return 0;
}