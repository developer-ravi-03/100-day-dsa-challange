// Leetcode : 206
//  Problem: Reverse a singly linked list.
// TC: O(n)
// SC: O(1)
#include <iostream>
using namespace std;
struct ListNode
{
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
class Solution
{
public:
  ListNode *reverseList(ListNode *head)
  {
    ListNode *prev = NULL;
    ListNode *curr = head;
    ListNode *next = NULL;

    while (curr != NULL)
    {
      next = curr->next;
      curr->next = prev;

      prev = curr;
      curr = next;
    }
    return prev;
  }
};
int main()
{

  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);

  // before reversing
  ListNode *temp1 = head;
  while (temp1 != NULL)
  {
    cout << temp1->val << " ";
    temp1 = temp1->next;
  }
  cout << endl;

  // reversing the linked list
  cout << "Reversing the linked list..." << endl;
  Solution sl;
  ListNode *temp = sl.reverseList(head);
  while (temp != NULL)
  {
    cout << temp->val << " ";
    temp = temp->next;
  }
  cout << endl;

  return 0;
}