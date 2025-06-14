#include <iostream>
using namespace std;
class Node
{
public:
  int data;
  Node *next;

  Node(int val)
  {
    data = val;
    next = NULL;
  }
};

class List
{
  Node *head;
  Node *tail;

public:
  List()
  {
    head = tail = NULL;
  }

  // for push front operation
  void push_front(int val) // O(1)
  {
    Node *newNode = new Node(val); // dynamic allocation

    if (head == NULL)
    {
      head = tail = newNode;
    }
    else
    {
      newNode->next = head;
      head = newNode;
    }
  }

  // insert value at any position
  void isert(int val, int pos) // O(n)
  {
    if (pos < 0)
    {
      cout << "Invalid position!" << endl;
      return;
    }

    if (pos == 0)
    {
      push_front(val);
      return;
    }

    Node *newNode = new Node(val);
    Node *temp = head;
    for (int i = 0; i < pos - 1; i++)
    {
      if (temp == NULL)
      {
        cout << "Position out of bounds!" << endl;
        return;
      }
      temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
  }

  // print linkedlist
  void printll() // O(n)
  {
    Node *temp = head;
    while (temp != NULL)
    {
      cout << temp->data << " -> ";
      temp = temp->next;
    }
    cout << "NULL" << endl;
  }
};

int main()
{
  List ll;
  // push front operation
  ll.push_front(1);
  ll.push_front(2);
  ll.push_front(3);

  ll.printll();

  // insert value at position 1
  ll.isert(4, 1);

  ll.printll();

  ll.isert(49, 59);

  ll.printll();
  return 0;
}