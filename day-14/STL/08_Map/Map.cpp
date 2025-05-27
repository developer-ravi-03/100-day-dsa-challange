#include <iostream>
#include <map>
using namespace std;
int main()
{
  map<string, int> m;
  m["tv"] = 100;
  m["laptop"] = 200;
  m["headphones"] = 50;
  m["tablet"] = 50;
  m["Watch"] = 50;

  m.insert({"earphone", 10});
  m.emplace("microphone", 20);
  m["tv"] = 90;
  m.erase("tv");
  for (auto p : m)
  {
    cout << p.first << " : " << p.second << endl;
  }

  cout << "count= " << m.count("laptop") << endl;
  cout << "count= " << m["laptop"] << endl;

  if (m.find("laptop") != m.end())
  {
    cout << "found\n";
  }
  else
  {
    cout << "Not found\n";
  }

  return 0;
}