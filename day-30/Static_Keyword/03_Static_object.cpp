#include <iostream>
using namespace std;
class ABC
{
public:
  ABC()
  {
    cout << "Constructor called" << endl;
  }

  ~ABC()
  {
    cout << "Destructor called" << endl;
  }
};
int main()
{
  // // in NOrmal Case, the constructor and destructor will be called
  // // when the object goes out of scope.
  // if (true)
  // {
  //   ABC obj1; // Static object
  // }
  // cout << "End of main function" << endl;

  // in case of static object, the constructor will be called
  if (true)
  {
    static ABC obj1; // Static object
  }
  cout << "End of main function" << endl;

  return 0;
}