// Bubble sort
// TC - O(nsquare)
#include <iostream>
using namespace std;

void BubbleSort(int arr[], int size)
{
  for (int i = 0; i < size - 1; i++)
  {
    for (int j = 0; j < size - i - 1; j++)
    {
      if (arr[j] > arr[j + 1])
      {
        swap(arr[j], arr[j + 1]);
      }
    }

    // for printing every loop step
    // for (int k = 0; k < size; k++)
    // {
    //   cout << arr[k] << "";
    // }
    // cout << endl;
  }
}

void printArray(int arr[], int size)
{
  for (int i = 0; i < size; i++)
  {
    cout << arr[i] << " ";
  }
}

int main()
{
  int arr[] = {2, 3, 1, 9, 5, 4, 6};
  int size = sizeof(arr) / sizeof(arr[0]);

  cout << "Before sorting: ";
  printArray(arr, size);

  BubbleSort(arr, size);
  cout << endl
       << "After sorting: ";
  printArray(arr, size);

  return 0;
}