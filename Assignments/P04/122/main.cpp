#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int main() 
{
  priority_queue <pair<string, string>> ns;
  vector <pair<string, string>> check;
  vector <char> digit; 
  vector <char> str;
  vector <char> root;
  vector <char> all;
  bool close = false;
  bool comma = false;
  bool rootex = false;
  bool connects = false;
  bool same = false;
  string ro;
  char n;
  int s = 0;
  int c = 0;
  int d = 0;

  while (cin >> n)
  {
    if (isdigit(n))
    {
      all.push_back(n);
      comma = false;
      close = false;
    }
    else if (n == 'L' || n == 'R' || n == ',')
    {
      close = false;
      if (n == 'L' || n == 'R')
      {
        all.push_back(n);
        comma = false;
      }
      else if (n == ',')
      {
        all.push_back(n);
        comma = true;
      }
    }
    else if (n == ')' && comma == true)
    {
      rootex = true;
      int r = all.size()-2;
      //cout << all[r] << endl;
      while (r >= 0)
      {
        if (isdigit(all[r]) && (all[r] != 'L' || all[r] != 'R' || all[r] != ','))
        {
          root.push_back(all[r]); 
          r--;
        }
        else if (all[r] == 'L' || all[r] == 'R' || all[r] == ',')
          break;
      }

      for (int i = root.size()-1; i >= 0; i--)
        ro.push_back(root[i]);

      //cout << ro << endl;

      if (all[all.size()-1] == ',')
        all.pop_back(); 
      for (int i = 0; i < root.size(); i++)
      {
        //cout << all[all.size()-1];
        if (root[i] == all[all.size()-1])
          all.pop_back();
      } //cout << endl;
      
      root.clear();
      ns.push(make_pair("", ro)); 
      comma = false;

      //cout << ro << endl;
    }
    else if (n == ')' && close == true)
    {
      /*for (int i = 0; i < all.size(); i++)
        cout << all[i];
      cout << endl;*/
      for (int i = 0; i < all.size(); i++)
      {
        if (isdigit(all[i]))
        {
          digit.push_back(all[i]);
          /*
          if (!str.empty())
          {
            while (s < str.size())
            {
              cout << str[s];
              s++;
            } cout << " ";
          }*/
        }
        else if (all[i] == 'L' || all[i] == 'R')
        {
          str.push_back(all[i]);
          //cout << all[i] << "/";
          /*while (s < str.size())
            {
              cout << str[s];
              s++;
            } cout << " ";*/

          //https://www.techiedelight.com/convert-vector-chars-std-string/
          
          if (i == all.size()-1 || isdigit(all[i+1]))
          {
            string s;
            string d;
            for (char c: str)
              s.push_back(c);
            for (char c: digit)
              d.push_back(c);

            //cout << s << " " << d << " ";
            ns.push(make_pair(s, d));

            str.clear();
            digit.clear();
          }
        }
      }
      while (!ns.empty())
      {
        //cout << ns.top().first << ns.top().second << " ";
        check.push_back(ns.top());
        ns.pop();
      }
      //cout << endl;

      for (int i = 0; i < check.size(); i++)
      {
        //cout << check[i].first << check[i].second << " ";
        for (int j = 0; j < check.size(); j++)
        {
          if (i != j)
          {
            //cout << check[i].first << "/" << check[j].first << "\n";
            if (check[i].first == check[j].first)
            {
              same = true;
              break;
            }
          }

          if (check[i].first.length() >= 2)
          {
            string si(check[i].first.begin(), check[i].first.end()-1);
            //cout << si << " " << check[j].first << endl;

            if (si == check[j].first)
            {
              //cout << "c";
              connects = true;
              break;
            }
            else if (j == check.size()-1 && connects == false)
            {
              //cout << "f\n";
              connects = false;
              c = -1;
              break;
            }
          }
        }

        if (connects == false)
          break;
      } //cout << endl;

      if (rootex == false || (connects == false && c == -1) || same == true)
        cout << "not complete\n";
      else if (c == 0 && rootex == true && same == false)
      {
        //cout << "print out ";
        string rootstr = check.back().second; 
        check.pop_back();
        vector <pair<string, string>> left;
        vector <pair<string, string>> right;
        vector <pair<string, string>> checker;
        int size;
        int l = -1;
        int r = -1;

        for (int i = 0; i < check.size(); i++)
        {
          if (check[i].first[0] == 'L')
            left.push_back(check[i]);
          else if (check[i].first[0] == 'R')
            right.push_back(check[i]);
        }
        check.clear();
        //cout << check.size() << endl;

        /*for (int i = 0; i < left.size(); i++)
          cout << left[i].first << left[i].second << " ";
        cout << endl;
        for (int i = 0; i < right.size(); i++)
          cout << right[i].first << right[i].second << " ";
        cout << endl;*/
        //cout << right.size() << " " << left.size() << " ";

        if (right.size() > 0 && left.size() == 0)
        {
          checker.push_back(right[right.size()-1]);
          right.pop_back();
          for (int i = right.size()-1; i >= 0; i--)
          {
            size = right[i].first.size();
            for (int j = right.size()-1; j >= 0; j--)
            {
              if (size == right[j].first.size() && !isdigit(right[j].first[0]))
              {
                checker.push_back(right[j]);
                //cout << left[j].first << left[j].second << " ";
                right[j].first = "1";
                right[j].second = "1";
              }
            }
          }
          cout << rootstr << " ";
          for (int i = 0; i < checker.size(); i++)
            cout << checker[i].second << " ";
          cout << endl;
        }
        else if (left.size() > 0 && right.size() == 0)
        {
          //cout << left[left.size()-1].first << left[left.size()-1].second << " ";
          check.push_back(left[left.size()-1]);
          //cout << left[left.size()-1].first << left[left.size()-1].second << endl;
          left.pop_back();
          for (int i = left.size()-1; i >= 0; i--)
          {
            size = left[i].first.size();
            for (int j = left.size()-1; j >= 0; j--)
            {
              if (size == left[j].first.size() && !isdigit(left[j].first[0]))
              {
                check.push_back(left[j]);
                //cout << left[j].first << left[j].second << " ";
                left[j].first = "1";
                left[j].second = "1";
              }
            }
          }
          cout << rootstr << " ";
          for (int i = 0; i < check.size(); i++)
            cout << check[i].second << " ";
          cout << endl;
        } 
        else if (left.size() > 0 && right.size() > 0)
        {
          //cout << left[left.size()-1].first << left[left.size()-1].second << " ";
          check.push_back(left[left.size()-1]);
          //cout << left[left.size()-1].first << left[left.size()-1].second << endl;
          left.pop_back();
          for (int i = left.size()-1; i >= 0; i--)
          {
            size = left[i].first.size();
            for (int j = left.size()-1; j >= 0; j--)
            {
              if (size == left[j].first.size() && !isdigit(left[j].first[0]))
              {
                check.push_back(left[j]);
                //cout << left[j].first << left[j].second << " ";
                left[j].first = "1";
                left[j].second = "1";
              }
            }
          }

          checker.push_back(right[right.size()-1]);
          right.pop_back();
          for (int i = right.size()-1; i >= 0; i--)
          {
            size = right[i].first.size();
            for (int j = right.size()-1; j >= 0; j--)
            {
              if (size == right[j].first.size() && !isdigit(right[j].first[0]))
              {
                checker.push_back(right[j]);
                //cout << left[j].first << left[j].second << " ";
                right[j].first = "1";
                right[j].second = "1";
              }
            }
          }

          int s = 0;
          int t = 0;
          cout << rootstr << " ";
          while (s < check.size() || t < checker.size())
          {
            //cout << check[s].first.size() << " " << checker[s].first.size() << "    ";
            if (s >= check.size() && t < checker.size())
            {
              while (t < checker.size())
              {
                cout << checker[t].second << " ";
                t++;
              }
            }
            else if (s < check.size() && t >= checker.size())
            {
              while (s < check.size()-1)
              {
                s++;
                cout << /*"s: " << s << " " <<*/ check[s].second << " ";
              }
            }
            else if (s < check.size() && t < checker.size())
            { //check[s].first.size() == checker[t].first.size()
              if (s == 0 && t == 0)
              {
                cout << check[s].second << " ";
                cout << checker[t].second << " ";
              }
              else if (s > 0 && t > 0)
              {
                int l = s+1; //+1???
                int m = t+1;
                size = check[t].first.size();

                cout << check[s].second << " ";
                while (size == check[l].first.size() && l < check.size())
                {
                  cout << check[l].second << " ";
                  l++;
                }

                cout << checker[t].second << " ";
                while (size == check[m].first.size() && m < checker.size())
                {
                  cout << check[m].second << " ";
                  m++;
                }
              }
            }

            s++;
            t++;
          }
          cout << endl;

          /*for (int i = 0; i < check.size(); i++)
            cout << check[i].first << check[i].second << " ";
          cout << endl;
          for (int i = 0; i < checker.size(); i++)
            cout << checker[i].first << checker[i].second << " ";*/
          //cout << endl << endl;
        }

        right.clear();
        left.clear();
        size = -1;
      }
      
      while (!ns.empty())
        ns.pop();

      all.clear();
      digit.clear();
      str.clear();
      root.clear();
      check.clear();
      ro = "";
      close = false;
      connects = false;
      comma = false;
      rootex = false;
      same = false;

      s = 0;
      d = 0;
      c = 0;
    }

    if (n == '(')
      close = true;
    //cout << lst << " " << n << endl;
  }
}
