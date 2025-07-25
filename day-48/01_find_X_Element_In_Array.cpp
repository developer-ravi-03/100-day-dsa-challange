#include <iostream>
using namespace std;
int main()
{
  int size;
  cout << "Enter Size of array :";
  cin >> size;
  int arr[size];
  cout << "Enter element : ";
  for (int i = 0; i < size; i++)
  {
    cin >> arr[i];
  }

  bool flag = false;
  int x;
  cout << "Enter what do you want to find";
  cin >> x;
  for (int i = 0; i < size; i++)
  {
    if (arr[i] == x)
    {
      flag = true;
    }
  }

  if (!flag)
    cout << "not found";
  else
    cout << "found";

  return 0;
}