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

  //  search for an element
  int search(int key) // O(n)
  {
    Node *temp = head;
    int idx = 0;
    while (temp != NULL)
    {
      if (temp->data == key)
      {
        return idx; // return the position of the found element
      }
      temp = temp->next;
      idx++;
    }
    return -1; // return -1 if not found
  }
};

int main()
{
  List ll;
  // push front operation
  ll.push_front(1);
  ll.push_front(2);
  ll.push_front(3);

  ll.isert(4, 1);

  ll.printll();

  cout << "Searching for 2: " << ll.search(2) << endl; // should return 1
  cout << "Searching for 4: " << ll.search(4) << endl; // should return 1

  return 0;
}