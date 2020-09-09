#include <iostream>
using namespace std;

int main() 
{
  int t, small, big, surv = 0;

  cin >> t;
  for (int i = 0; i < t; i++)
  {
    cin >> small >> big;
    if (small > big)
    {
      int s = small;
      small = big;
      big = s;
    }

    cin >> surv;

    if (surv < small)
    {
      int s = small;
      small = surv;
      surv = s;
    }
    else if (surv > big)
    {
      int s = big;
      big = surv;
      surv = s; 
    }

    cout << "Case " << i+1 << ": " << surv << endl;
  }
}
