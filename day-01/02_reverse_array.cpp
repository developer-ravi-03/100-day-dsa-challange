#include <iostream>
using namespace std;
void reverseArray(int arr[], int size)
{
  int start = 0;
  int end = size - 1;
  while (start < end)
  {
    swap(arr[start], arr[end]);
    start++;
    end--;
  }
}

void printarray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
  cout << endl;
}
int main()
{
  int arr[] = {1, 2, 3, 4, 5};
  int n = sizeof(arr) / sizeof(arr[0]);
  cout << "Original array: ";
  printarray(arr, n);

  reverseArray(arr, n);
  cout << "Reversed array: ";
  printarray(arr, n);
  return 0;
}