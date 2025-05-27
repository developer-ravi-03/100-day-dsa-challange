#include <iostream>
#include <map>
using namespace std;
int main()
{
  multimap<string, int> m;

  m.insert({"earphone", 10});
  m.emplace("microphone", 20);
  m.emplace("microphone", 20);
  m.emplace("microphone", 20);
  m.emplace("microphone", 20);
  // m.erase("microphone");
  m.erase(m.find("microphone"));

  for (auto p : m)
  {
    cout << p.first << " : " << p.second << endl;
  }

  return 0;
}