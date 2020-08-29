#include <iostream>
using namespace std;

int main() 
{
  string k = "";
  int t, don, amount = 0;

  cin >> t; 
  for (int i = 0; i < t; i++)
  {
    cin >> k;
    if (k == "donate")
    {
      cin >> don;
      amount += don;
    }
    else if (k == "report")
      cout << amount << endl;
  }
}
