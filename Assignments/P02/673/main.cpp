#include <vector>
#include <string>
#include <iostream> 
using namespace std;

int main() 
{
  int num = 0;
  bool yn = false;
  bool close = true;
  string str = "";
  vector <char> stack; 

  cin >> num;
  cin.ignore();

  for (int i = 0; i < num; i++)
  { 
    getline(cin, str);
    //cout << str << " ";
    
    if (str.length() == 0) 
      yn = true;

    for (char const &para: str) 
    {
      if (str.length() % 2 == 0)
      {
        if (para == '(')
          stack.push_back('(');
        else if (para == '[')
          stack.push_back('[');
        else if (para == ')')
        {
          if (!stack.empty())
          {
            if (stack.back() == '(')
            {
              yn = true;
              stack.pop_back();
            }
            else if (stack.back() == '[')
              close = false;
            else
              yn = false;
          }
          else
          {
            yn = false;
            close = false;
          }
        }
        else if (para == ']')
        {
          if (!stack.empty())
          {
            if (stack.back() == '[')
            {
              yn = true;
              stack.pop_back();
            }
            else if (stack.back() == '(')
              close = false;
            else
              yn = false;
          }
          else
          {
            yn = false;
            close = false;
          }
        }
      }
    }
    if (!stack.empty())
      yn = false;
    
    stack.clear();  
    if (close == false)
      cout << "No\n";
    else
    {
      if (yn == true)
        cout << "Yes\n";
      else
        cout << "No\n";
    }

    yn = false;
    close = true;
  }
}
