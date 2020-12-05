#include <iostream>
using namespace std;

int n, m;
int pegs[3][252];
int top[3];

void Print() 
{
  for (int i = 0; i < 3; i++)
  {
    cout << char('A' + i) << "=>";
    if (top[i] >= 0) 
    {
      cout << "  ";
      for (int j = 0; j <= top[i]; j++)
        cout << " " << pegs[i][j];
    }
    cout << endl;
  }
  cout << endl;
}

void Towers(int a, int b, int c, int n) 
{
  if (n > 0) 
  {
    Towers(a, c, b, n-1);

    pegs[c][++top[c]] = pegs[a][top[a]--];

    if (m-- > 0) 
      Print();
    else 
      return;
        
    Towers(b, a, c, n-1);
  }
}

int main() 
{
  int times = 1;

  cin >> n >> m;
  while (n != 0 && m != 0) 
  {
    cout << "Problem #" << times << endl << endl;

    for (int i = n; i >= 1; i--) 
      pegs[0][n-i] = i;

    top[0] = n - 1;
    top[1] = top[2] = -1;

    Print();
    Towers(0, 1, 2, n);

    times++;
    cin >> n >> m;
  }
}
