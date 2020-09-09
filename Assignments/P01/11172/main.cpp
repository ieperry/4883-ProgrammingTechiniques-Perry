#include <iostream>
using namespace std;

int main() 
{
  int t, a, b = 0;

  cin >> t; 
  for(int i = 0; i < t; i++)
    {
      cin >> a >> b;
      if (a < b)
        cout << "<\n";
      else if (a > b)
        cout << ">\n";
      else
        cout << "=\n";
    }
}
