// Delete the Middle Node of a Linked List
// Leetcode:2095
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
  ListNode *deleteMiddle(ListNode *head)
  {
    ListNode *slow = head;
    ListNode *fast = head;
    ListNode *prev = NULL;

    while (fast != NULL && fast->next != NULL)
    {
      prev = slow;
      slow = slow->next;
      fast = fast->next->next;
    }

    prev->next = slow->next;
    delete slow;
    return head;
  }
};
int main()
{
  // Create a test linked list: 1->2->3->4->5
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);

  Solution sol;
  head = sol.deleteMiddle(head);

  // Print the result: 1->2->4->5
  ListNode *temp = head;
  while (temp != NULL)
  {
    cout << temp->val << "->";
    temp = temp->next;
  }
  cout << "NULL" << endl;
  return 0;
}