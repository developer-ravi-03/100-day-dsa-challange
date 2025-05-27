#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
  unordered_map<string, int> m;

  m.emplace("microphone", 20);
  m.emplace("laptop", 20);
  m.emplace("tv", 20);
  m.emplace("mobile", 20);
  // m.erase("microphone");
  // m.erase(m.find("microphone"));

  for (auto p : m)
  {
    cout << p.first << " : " << p.second << endl;
  }

  return 0;
}