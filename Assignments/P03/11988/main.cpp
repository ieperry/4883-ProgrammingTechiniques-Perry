#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() 
{
  string digits;
  char el;
  queue <char> order; 
  vector <char> st; 
  vector <char> ststr;

  while(getline(cin, digits))
  {
    bool para = false;
    for (char const &c: digits)
    {
      if (c == '[')
      {
        para = true;
        st.push_back(c);
      }
      else if (c == ']')
      {
        para = false;
        order.emplace(c);
      }
      else if (c != '[' || c != ']')
      {
        if (para == true)
        {
          st.push_back(c);
        }
        else if (para == false)
        {
          order.emplace(c);
        }
      }
    }

    while (!st.empty())
    {
      if (st.back() != '[')
      {
        ststr.push_back(st.back());
        st.pop_back();
      }
      else if (st.back() == '[')
      {
        st.pop_back();
        while (!ststr.empty())
        {
          cout << ststr.back();
          ststr.pop_back();
        }
      }
    }

    while (!order.empty())
    {
      if (order.front() == ']')
        order.pop();
      else if (order.front() != ']')
      {
        cout << order.front();
        order.pop();
      }
    }

    st.clear();
    cout << endl;
  }
}
