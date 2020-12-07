#include <iostream>
#include <queue>
#include <iomanip>
#include <string>
using namespace std;

int main() 
{
  priority_queue <pair<string, double>> trees;
  vector <pair<string, double>> wood;
  string name, blank;
  int amt, total = 0;
  int ind = 0;

  cin >> amt;
  cin.ignore();
  for (int i = 0; i < amt; i++)
  {
    if (i == 0)
      cin.ignore();
    while (getline(cin, name, '\n'))
    {
      if (name == "")
        break;
      //cout << name << endl;
      trees.push(make_pair(name, 1));
      total++;
    }
    //cout << total << endl;

    wood.push_back(trees.top());
    trees.pop();
    while (!trees.empty())
    {
      //cout << trees.top().first << " " << trees.top().second << endl;
      if (trees.top().first == wood[ind].first)
        wood[ind].second++;
      else if (trees.top().first != wood[ind].first)
      {
        wood.push_back(trees.top());
        ind++;
      }
      trees.pop();
    }

    for (int j = 0; j < wood.size(); j++)
    {
      wood[j].second = wood[j].second / total;
      wood[j].second = wood[j].second * 100;
    }

    for (int j = wood.size()-1; j >= 0; j--)
    {
      cout << fixed << setprecision(4);
      cout << wood[j].first << " " << wood[j].second << endl;
    }
    
    if (amt > 0 && i != amt-1)
      cout << endl;

    if (!trees.empty())
      trees.pop();

    wood.clear();
    ind = 0;
    total = 0;
    //cin.ignore();
  }
}
