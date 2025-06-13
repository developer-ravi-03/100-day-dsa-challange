// it is wrapping data and functions together into a single unit called a class.
// data hiding is a key aspect of encapsulation, where the internal state of an object is hidden from the outside world.
#include <iostream>
using namespace std;
class BankingSystem
{
private:
  double balance;  // private property to store balance
  string password; // data hiding
public:
  int accountNumber;
  string accountHolderName;
};

int main()
{

  return 0;
}