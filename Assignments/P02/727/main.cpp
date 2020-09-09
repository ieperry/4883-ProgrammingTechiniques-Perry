#include <vector>
#include <string>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
using namespace std;

int main() 
{
  //https://www.interviewsansar.com/isdigit-c-check-if-char-is-digit/

  int num = 0;
  vector <string> op;
  string space, math;

  cin >> num;
  getline(cin, space);
  getline(cin, space);

  for (int i = 0; i < num; i++)
  {
    getline(cin, math);
    
    while (math != "")
    {
      if (isdigit(math[0]))
        cout << math;
      else
      {
        if (math == "(")
          op.push_back("(");
        else if ((math == "*" || math == "/" || math == "+" || math == "-") && (op.empty() || op.back() == "("))
          op.push_back(math);
        else if ((math == "*" || math == "/") && (op.back() == "+" || op.back() == "-"))
          op.push_back(math);
        else if ((math == "+" || math == "-") && (op.back() == "*" || op.back() == "/"))
        {
          while (!op.empty() && op.back() != "(")
          {
            cout << op.back();
            op.pop_back();
          }
          op.push_back(math);
        }
        else if (math == ")")
        {
          while (op.back() != "(")
          {
            cout << op.back();
            op.pop_back();
          }
          op.pop_back();
        }
        else if (math == "*" && op.back() == "*")
        {
          cout << "*";
          op.pop_back();
          op.push_back(math);
        }
        else if (math == "*" && op.back() == "/")
        {
          cout << "/";
          op.pop_back();
          op.push_back(math);
        }
        else if (math == "/" && op.back() == "/")
        {
          cout << "/";
          op.pop_back();
          op.push_back(math);
        }
        else if (math == "/" && op.back() == "*")
        {
          cout << "*";
          op.pop_back();
          op.push_back(math);
        }
        else if (math == "+" && op.back() == "+")
        {
          cout << "+";
          op.pop_back();
          op.push_back(math);
        }
        else if (math == "+" && op.back() == "-")
        {
          cout << "-";
          op.pop_back();
          op.push_back(math);
        }
        else if (math == "-" && op.back() == "-")
        {
          cout << "-";
          op.pop_back();
          op.push_back(math);
        }
        else if (math == "-" && op.back() == "+")
        {
          cout << "+";
          op.pop_back();
          op.push_back(math);
        }
      }
      getline(cin, math);
    }
    while (!op.empty())
    {
      cout << op.back();
      op.pop_back();
    }
    cout << endl;
    if (i + 1 != num)
      cout << endl;
    op.clear();
  }
  op.clear();
}
