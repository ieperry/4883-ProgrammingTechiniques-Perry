#include <iostream>
#include <vector>
using namespace std;

void Towers (int n, int &times, char beg, char mid, char dest, vector <int> &a, vector <int> &b, vector <int> &c)
{
  //cout << times << endl;
  //if (times >= 0)
  //{
    //beg = 65, mid = 66, dest = 67
    if (times < 0)
      return;
    else if (times > 0)
    {
      if (n == 1)
      {
        //cout << "Disk " << n << " goes from " << beg << " to " << dest << endl;
        if (dest == 65)
          a.push_back(n);
        else if (dest == 66)
          b.push_back(n);
        else if (dest == 67)
          c.push_back(n);

        if (beg == 65)
          a.pop_back();
        else if (beg == 66)
          b.pop_back();
        else if (beg == 67)
          c.pop_back();

        times--;
        //cout << times << endl;

        cout << "A=>   ";
        for (int i = 0; i < a.size(); i++)
          cout << a[i] << " ";
        cout << endl;
        cout << "B=>   ";
        for (int i = 0; i < b.size(); i++)
          cout << b[i] << " ";
        cout << endl;
        cout << "C=>   ";
        for (int i = 0; i < c.size(); i++)
          cout << c[i] << " ";
        cout << endl << endl;

        return;
      }
      else 
      {
        Towers(n-1, times, beg, dest, mid, a, b, c);
        //cout << "Disk " << n << " goes from " << beg << " to " << dest << endl;	

        if (times > 0)
        {
          if (dest == 65)
            a.push_back(n);
          else if (dest == 66)
            b.push_back(n);
          else if (dest == 67)
            c.push_back(n);

          if (beg == 65)
            a.pop_back();
          else if (beg == 66)
            b.pop_back();
          else if (beg == 67)
            c.pop_back();
          

          times--;
          //cout << times << endl;

          cout << "A=>   ";
          for (int i = 0; i < a.size(); i++)
            cout << a[i] << " ";
          cout << endl;
          cout << "B=>   ";
          for (int i = 0; i < b.size(); i++)
            cout << b[i] << " ";
          cout << endl;
          cout << "C=>   ";
          for (int i = 0; i < c.size(); i++)
            cout << c[i] << " ";
          cout << endl << endl;
        }

        Towers(n-1, times, mid, beg, dest, a, b, c);
      }
    }
}

int main() 
{
  int num = 1;
  int m, n;
  vector <int> a, b, c;

  cin >> m >> n;
  while (m != 0 && n != 0)
  {
    for (int i = m; i >= 1; i--)
      a.push_back(i);

    cout << "Problem #" << num << endl << endl;

    cout << "A=>   ";
    for (int i = 0; i < a.size(); i++)
      cout << a[i] << " ";
    cout << endl << "B=>   " << endl << "C=>   " << endl << endl;

    Towers (m, n, 'A', 'B', 'C', a, b, c);

    num++;
    cin >> m >> n;
    a.clear();
    b.clear();
    c.clear();
  }
}
