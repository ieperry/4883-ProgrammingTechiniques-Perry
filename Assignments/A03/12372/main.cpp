#include <iostream>
using namespace std;

int main() 
{
  int t, l, w, h = 0;

  cin >> t;
  for (int i = 0; i < t; i++)
  {
    cin >> l >> w >> h;
    if (l <= 20 && w <= 20 && h <= 20)
      cout << "Case " << 1+i << ": good\n";
    else 
      cout << "Case " << 1+i << ": bad\n";
  }
}
