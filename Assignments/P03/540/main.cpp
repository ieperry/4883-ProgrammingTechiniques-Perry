#include <iostream>
#include <vector>
#include <utility>
#include <string>
using namespace std;

int main() 
{
  int scen = 0; //Scenario #
  int teams = 0; //# of teams
  int teamnum = 0;
  int teamems = 0; //the team members read in
  int currteam = 0;
  string command = "";
  int num = 0;
  vector <pair<int, int>> q;
  vector <pair<int, int>> tq; 

  cin >> teams;
  while (teams != 0)
  {
  scen++;
  cout << "Scenario #" << scen << endl;
  for (int i = 0; i < teams; i++)
  {
    cin >> teamnum;
    tq.resize((teamnum+currteam)+1);
    //place size in vector
    tq[currteam].first = teamnum;
    tq[currteam].second = -1;

    //place rest of numbers in team vector
    for (int j = 1; j <= teamnum; j++)
    {
      cin >> teamems;
      tq[(j+currteam)].first = teamems;
      tq[(j+currteam)].second = i;
    }
    //place last number in vector
    tq[(currteam+teamnum)].first = teamems;
    tq[(currteam+teamnum)].second = i;
    //add one more number to compensate for size
    currteam = currteam + (teamnum+1);
  }
  
  cin >> command;
  while (command != "STOP")
  {
    if (command == "ENQUEUE")
    {
      cin  >> num;
      for (int i = 0; i < tq.size(); i++)
      {
        if (tq[i].second != -1)
        {
          if (tq[i].first == num)
          {
            q.push_back(tq[i]); 
            if (q.size() > 2)
            {
              for (int k = q.size()-2; k >= 0; k--)
              {
                if (q.back().second == q[k].second)
                {
                  pair<int, int> temp = q.back();
                  int j = q.size() - 1;
                  while (j != k+1)
                  {
                    q[j] = q[j-1];
                    j--;
                  }
                  q[j] = temp;
                  break;
                }
              }
            }
            break;
          }
        }
      }
    }
    else if (command == "DEQUEUE")
    {
      if (!q.empty())
      {
        cout << q.front().first << endl;
        q.erase(q.begin());
      }
    }
      
    cin >> command;
  }
  cout << endl;

  currteam = 0;
  tq.clear();
  q.clear();
  cin >> teams;
  }
}
