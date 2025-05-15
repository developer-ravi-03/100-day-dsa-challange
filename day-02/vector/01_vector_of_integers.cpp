#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Creating a vector of integers
    vector<int> numbers;

    // Adding elements to the vector
    numbers.push_back(10);
    numbers.push_back(20);
    numbers.push_back(30);

    // Accessing elements using index
    cout << "First element: " << numbers[0] << endl;

    // Iterating over the vector
    cout << "All elements: ";
    for (int i = 0; i < numbers.size(); ++i)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    numbers.pop_back();
    cout << "All elements after deleting: ";
    for (int i = 0; i < numbers.size(); ++i)
    {
        cout << numbers[i] << " ";
    }
    cout << endl;

    return 0;
}
