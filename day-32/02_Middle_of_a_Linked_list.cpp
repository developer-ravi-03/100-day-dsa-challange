#include <iostream>
using namespace std;
struct Node
{
  int data;
  Node *next;
  Node(int val) : data(val), next(NULL) {}
};

int length(Node *head)
{
  int count = 0;
  Node *temp = head;
  while (temp != NULL)
  {
    count++;
    temp = temp->next;
  }
  return count;
}

int midVal(Node *head, int mid)
{
  Node *temp = head;
  int count = 1;
  while (temp != NULL)
  {
    if (count == mid)
    {
      cout << "Middle value: " << temp->data << endl;
      return temp->data;
    }
    count++;
    temp = temp->next;
  }
  return -1; // In case the list is empty or mid is out of bounds
}

int main()
{
  Node *head = new Node(1);
  head->next = new Node(2);
  head->next->next = new Node(3);
  head->next->next->next = new Node(4);
  head->next->next->next->next = new Node(5);
  head->next->next->next->next->next = new Node(6);

  Node *temp = head;
  while (temp != NULL)
  {
    cout << temp->data << " ";
    temp = temp->next;
  }

  int len = length(head);
  int mid = (len / 2) + 1;
  midVal(head, mid);
  return 0;
}