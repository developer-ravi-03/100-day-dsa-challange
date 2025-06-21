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

class CicularList
{
  Node *head;
  Node *tail;

public:
  CicularList()
  {
    head = tail = NULL;
  }

  // insert at the begining and head
  void insertAtHead(int val)
  {
    Node *newNode = new Node(val);
    if (tail == NULL)
    {
      head = tail = newNode;
      tail->next = head;
    }
    else
    {
      newNode->next = head;
      head = newNode;
      tail->next = head;
    }
  }

  // insert at the tail
  void insertAtTail(int val)
  {
    Node *newNode = new Node(val);
    if (head == NULL)
    {
      head = tail = newNode;
      tail->next = head;
    }
    else
    {
      newNode->next = head;
      tail->next = newNode;
      tail = newNode;
    }
  }

  // delete at head
  void deleteAtHead()
  {
    if (head == NULL)
      return;

    else if (head == tail)
    {
      delete head;
      head = tail = NULL;
    }
    else
    {
      Node *temp = head;
      head = head->next;
      tail->next = head;
      temp->next = NULL;
      delete temp;
    }
  }

  // delete at tail
  void deleteAtTail()
  {
    if (head == NULL)
      return;

    else if (head == tail)
    {
      delete head;
      head = tail = NULL;
    }
    else
    {
      Node *temp = tail;
      Node *prev = head;
      while (prev->next != tail)
      {
        prev = prev->next;
      }
      tail = prev;
      tail->next = head;
      temp->next = NULL;
      delete temp;
    }
  }

  // print the list
  void printList()
  {
    if (head == NULL)
      return;
    cout << "Circular Linked List: " << endl;

    cout << head->data << "->";
    Node *temp = head->next;

    while (temp != head)
    {
      cout << temp->data << "->";
      temp = temp->next;
    }
    cout << temp->data << endl;
  }
};
using namespace std;
int main()
{
  CicularList cll;
  cll.insertAtHead(1);
  cll.insertAtHead(2);
  cll.insertAtHead(3);

  cll.printList();

  cll.insertAtTail(4);
  cll.insertAtTail(5);
  cll.insertAtTail(6);

  cll.printList();

  cll.deleteAtHead();
  cll.deleteAtHead();
  cll.printList();

  cll.deleteAtTail();
  cll.deleteAtTail();
  cll.printList();

  return 0;
}