// Leetcode : 876
//  Problem: Find the middle of a linked list using brute force.
//  TC: O(n*n)
//  SC: O(1)
#include <iostream>
using namespace std;

struct ListNode
{
  int val;
  ListNode *next;
  // Constructors for ListNode
  // Default constructor initializes val to 0 and next to nullptr
  ListNode() : val(0), next(nullptr) {}
  // Constructor that initializes val with a given value and next to nullptr
  // Constructor that initializes val with a given value and next with a given ListNode pointer
  ListNode(int x) : val(x), next(nullptr) {}
  // Constructor that initializes val with a given value and next with a given ListNode pointer
  // This allows for creating a ListNode with a specific value and linking it to another ListNode
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  ListNode *midVal(ListNode *head, int mid)
  {
    ListNode *temp = head;
    int count = 1;
    while (temp != NULL)
    {
      if (count == mid)
        return temp;
      count++;
      temp = temp->next;
    }
    return NULL;
  }

  ListNode *middleNode(ListNode *head)
  {
    ListNode *temp = head;
    int count = 0;
    while (temp != NULL)
    {
      count++;
      temp = temp->next;
    }

    int mid = (count / 2) + 1;
    return midVal(head, mid);
  }
};

int main()
{
  ListNode *head = new ListNode(1);
  head->next = new ListNode(2);
  head->next->next = new ListNode(3);
  head->next->next->next = new ListNode(4);
  head->next->next->next->next = new ListNode(5);
  head->next->next->next->next->next = new ListNode(6);

  Solution sl;
  ListNode *midNode = sl.middleNode(head);
  if (midNode != NULL)
  {
    cout << "Middle value: " << midNode->val << endl;
  }
  else
  {
    cout << "The list is empty." << endl;
  }

  return 0;
}