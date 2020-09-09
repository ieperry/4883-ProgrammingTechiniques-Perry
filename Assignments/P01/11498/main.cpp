#include <iostream>
using namespace std;

int main() 
{
  int k, n, m, x, y, j = 0;

  cin >> k;

  while (k > 0 && j < 15)
  {
    cin >> n >> m;

    for (int i = 0; i < k; i++)
    {
      cin >> x >> y;

      if (x > n && y > m)
        cout << "NE\n";
      else if (x < n && y > m)
        cout << "NO\n";
      else if (x < n && y < m)
        cout << "SO\n";
      else if (x > n && y < m)
        cout << "SE\n";
      else if (x == n || y == m)
        cout << "divisa\n";
    }
    cin >> k;
  }
}
