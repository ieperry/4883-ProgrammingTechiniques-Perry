#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int main() 
{
  bool close = false;
  char last = ' ';
  string node = "";
  string lr = "";
  string root = "";
  string value;
  vector <pair<string, string>> ns;
  vector <pair<string, string>> fin;
  vector <pair<string, string>> right;
  priority_queue <pair<string, string>> order;

  while (cin >> node)
  {
    //cout << node << endl;
    
    for (int i = 0; i < node.length(); i++)
    {
      if (node[i] == '(')
      {
        close = true;
        //cout << c << " ";
      }
      else if (node[i] != '(' && node[i] != ',' && node[i] != ')')
      {
        if (node[i+1] == ',' && node[i+2] == ')')
        {
          vector <char> st;
          char end = node[i];
          int h = i;
          while (node[h] != '(')
          {
            //cout << " " << node[h];
            st.push_back(node[h]);
            h--;
          } 
          
          for (int q = st.size()-1; q >= 0 ; q--)
            root.push_back(st[q]);

          value = "";
        }
        else if (isdigit(node[i]))
        {
          //cout << node[i];
          value.push_back(node[i]);
        }
        else if (isdigit(node[i]) && node[i+1] != ',')
        {
          value.push_back(node[i]);
          //cout << value << " ";
        }
        else if (node[i] == 'L' || node[i] == 'R')
        {
          lr.push_back(node[i]);
          if (node[i+1] == ')')
          {
            //cout << " " << value << ", " << lr << ". ";
            order.push(make_pair(lr, value)); 
            ns.emplace_back(value, lr);
            //int e = ns.size()-1;

            /*Sort(e, ns); 
            if (e == -1)
            {
              cout << "not complete\n";
              break;
            }*/

            //cout << value << " ";
            lr = ""; 
            value = "";
          }
        }
        else if (!isdigit(node[i+1]) && node[i+1] == ',')
        {
          //https://www.techiedelight.com/convert-vector-chars-std-string/
          if (isdigit(node[i]) /*&& node[i+2] == ')'*/)
          {
            value.push_back(node[i]);
            //cout << " " << value << endl;
          }
          
          /*for (int n = 0; n < value.size(); n++)
            cout << value[n];
          cout << " ";*/
        }

        close = false;
      }
      else if (node[i] == ')')
      {
        if (close == true)
        {
          if (root != "")
          {
            //order.push(make_pair(-1, root));
            ns.emplace_back(root, ""); 
            order.push(make_pair("", root));
            bool found = false;
            bool same = false;
            //For each node, see if it has a parent
            for (int g = 0; g < ns.size(); g++)
            { 
              //cout << ns[g].second << "\n";
              
              //Search for node letter - 1 (ie LLL search for LL)
              string find;
              found = false;

              //Do not search for root, must begin with L or R
              if (ns[g].second.size() > 1)
              {
                for (int r = 0; r < ns[g].second.size()-1; r++)
                {
                  //cout << ns[g].second[r] << " ";
                  find.push_back(ns[g].second[r]);
                }
                //cout << endl;

                for (int j = 0; j < ns.size(); j++)
                {
                  //cout << j <<  ": " << ns[j].second << " ";
                  if (ns[j].second == find)
                  {
                    found = true;
                    break;
                  }
                }
                //cout << endl;
                if (found == false)
                {
                  cout << "not complete\n";
                  break;
                }
              }

              int x = g;

              for (int r = 0; r < ns.size(); r++)
              {
                if (x != r)
                {
                  //cout << ns[x].second << " " << ns[r].second << endl;
                  if (ns[x].second == ns[r].second)
                  {
                    same = true;
                    break;
                  }
                }
              }

              if (same == true)
                break;
            }

            /*
            while (!order.empty())
            {
              fin.push_back(order.top());
              order.pop();
            }
            for (int c = fin.size()-1; c >= 0; c--)
              cout <<  fin[c].second << " ";
            cout << endl;*/

            if (same == false)
            {
              while (!order.empty())
              {
                //cout << order.top().first << " " << order.top().second << " ";
                if (order.top().first == "" || order.top().first[0] == 'L')
                {
                  fin.push_back(order.top());
                  order.pop();
                }
                else if (order.top().first[0] == 'R')
                {
                  right.push_back(order.top());
                  order.pop();
                }
              } 
              
              if (!order.empty())
                cout << " y \n";

              /*for (int c = right.size()-1; c >= 0; c--)
                {
                  cout << right[c].second << " " << right[c].first << " ";
                  //r.push(right[c]);
                } //cout << endl;
                for (int c = fin.size()-1; c >= 0; c--)
                {
                  cout << fin[c].second << " " << fin[c].first << " ";
                  //l.push(fin[c]);
                } cout << endl;*/

              //root = insert(root, fin[fin.size()-1].second); 
              cout << fin[fin.size()-1].second << " ";
              fin.erase(fin.end()-1); 
              //cout << fin[fin.size()-1].second << endl;
              //cout << endl;
              int ltsize = 0;
              for (int q = fin.size()-1; q >= 0; q--)
              {
                for (int p = right.size()-1; p >= 0; p--)
                {
                  if (fin[q].first.size() == right[p].first.size() && ltsize != fin[q].first.size())
                  {
                    int s = q;
                    int t = p;
                    while (fin[s].first.size() == right[p].first.size())
                    {
                      //cout << "s " << fin[s].first << " " << right[p].first << " ";
                      //root = insert(root, fin[s].second);
                      cout << fin[s].second << " ";
                      s--;
                    }

                    while (fin[q].first.size() == right[t].first.size())
                    {
                      //cout << " t " << fin[q].first << " " << right[t].first << " ";
                      //root = insert(root, right[t].second);
                      cout << right[t].second << " ";
                      t--;
                    }
                    //cout << endl;
                    ltsize = fin[q].first.size();
                  }
                }
              }

              //printLevelOrder(root);
              cout << endl;
            }
          }
          else if (root == "")
            cout << "not complete\n";

          //cout << root << endl;
          root = "";
          ns.clear();
          fin.clear(); 
          right.clear();
          close = false;
          last = ' ';
          node = "";
          lr = "";
          value = "";
          //cout << endl;
        }
        else if (node[i+1] == last)
          cin >> last;

      }
    }
  }
}
