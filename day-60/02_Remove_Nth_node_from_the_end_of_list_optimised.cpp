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

    ListNode dummy(0, head);
    ListNode *fast = &dummy;
    ListNode *slow = &dummy;

    // Move fast n+1 steps ahead
    for (int i = 0; i <= n; ++i)
    {
      fast = fast->next;
    }

    // Move both pointers until fast reaches the end
    while (fast != nullptr)
    {
      fast = fast->next;
      slow = slow->next;
    }

    ListNode *toDelete = slow->next;
    slow->next = toDelete->next;
    delete toDelete;

    return dummy.next;
  }
};
int main()
{
  // Create a sample linked list: 1->2->3->4->5
  ListNode *head = new ListNode(1);
  // head->next = new ListNode(2);
  // head->next->next = new ListNode(3);
  // head->next->next->next = new ListNode(4);
  // head->next->next->next->next = new ListNode(5);

  int n = 1; // Remove 2nd node from end

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