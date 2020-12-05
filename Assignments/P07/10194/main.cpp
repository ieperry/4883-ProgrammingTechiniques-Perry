#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <sstream>
#include <algorithm>
using namespace std;

struct teams
{
  string name;
  int rank;
  int points;
  int games;
  int wins;
  int ties;
  int losses;
  int goalDiff;
  int goalScored;
  int goalAgainst;

  teams (string n)
  {
    name = n;
    rank = 0;
    points = 0;
    games = 0;
    wins = 0;
    ties = 0;
    losses = 0;
    goalDiff = 0;
    goalScored = 0;
    goalAgainst = 0;
  }

  teams (string n, int r)
  {
    name = n;
    rank = r;
    points = 0;
    games = 0;
    wins = 0;
    ties = 0;
    losses = 0;
    goalDiff = 0;
    goalScored = 0;
    goalAgainst = 0;
  }
};

bool CompareString (string a, string b)
{
  string x, y;
  x = a;
  y = b;
  transform(x.begin(), x.end(), x.begin(), ::tolower);
  transform(y.begin(), y.end(), y.begin(), ::tolower);
  //cout << x << " " << y << endl;
  return x < y;
}

bool Sort(const teams &a, const teams &b) 
{
  if (a.points != b.points)
    return a.points > b.points;

  if (a.wins != b.wins)
    return a.wins > b.wins;

  if (a.goalDiff != b.goalDiff)
    return a.goalDiff > b.goalDiff;

  if (a.goalScored != b.goalScored)
    return a.goalScored > b.goalScored;

  if (a.games != b.games)
    return a.games < b.games;

  string m = a.name;
  string n = b.name;

  return CompareString (m, n);
}

int main() 
{
  vector <teams> football {};
  string game, tourna, teamn;
  int tours, teamsAmt, gameAmt;

  cin >> tours;
  //cout << tours << endl;

  cin.ignore();
  for (int i = 0; i < tours; i++)
  {
    //cin >> t1;
    getline (cin, tourna, '\n');
    cout << tourna << endl;
    cin >> teamsAmt;
    //cout << teamsAmt << endl;
    //football.resize(teamsAmt);
    
    cin.ignore();
    for (int j = 0; j < teamsAmt; j++)
    {
      //cin >> team1;  
      getline(cin, teamn, '\n');
      //cout << teamn << endl;
      football.emplace_back(teams(teamn));
    }

    cin >> gameAmt;
    //cout << gameAmt << endl;
    cin.ignore();

    for (int j = 0; j < gameAmt; j++)
    {
      getline(cin, game, '\n');
      //cout << game << endl;
      vector <char> vs1;
      vector <char> vs2;
      vector <int> num;
      bool first = false;
      bool second = false;
      bool at = false;
      int score[2];
      int ind = 0;
      char last = ' ';

      for (char const &c: game) 
      {
        //cout << c << " " << last << " ";
        if (c != '#' && c != '@' && !isdigit(c) && second == false)
          vs1.push_back(c);
        else if (c != '#' && c != '@' && !isdigit(c) && second == true)
        {
          //cout << "2 ";
          vs2.push_back(c);
        }
        else if (c == '#' && first == false)
        {
          //cout << "1 ";
          /*for (int k = 0; k < vs1.size(); k++)
            cout << vs1[k];
          cout << endl;*/
          first = true;
          last = '#';
        }
        else if (c == '#' && first == true)
        {
          second = true;
          //cout << vs1[0] << " ";
        }
        else if (isdigit(c) && first == true)
        {
          int ic = c - 48;
          score[ind] = ic;
          //cout << c << " ";
          
          if (ind == 1)
          {
            bool equal;
            int ii = 0;
            for (auto& tt: football)
            {
              string s = tt.name;
              for (char const &is: s) 
              {
                //cout << is << " vs1 " << vs1[ii] << ". ";
                if (vs1[ii] == is)
                {
                  equal = true;
                  //cout << "t";
                }
                else
                {
                  equal = false;
                  break;
                }
                ii++;
              }
              //cout << endl;

              if (equal == true)
              {
                tt.games++;
                tt.goalScored = tt.goalScored + score[0];
                tt.goalAgainst = tt.goalAgainst + score[1];

                if (score[0] > score[1])
                {
                  tt.wins++;
                  tt.points = tt.points + 3;
                }
                else if (score[0] < score[1])
                  tt.losses++;
                else if (score[0] == score[1])
                {
                  tt.ties++;
                  tt.points = tt.points + 1;
                }
                break;
              }

              equal = true;
              ii = 0;
            }
            vs1.clear();
          }

          ind++;
          last = ' ';
        }
      }

      bool equal;
      int ii = 0;
      for (auto& tt: football)
      {
        string s = tt.name;
        for (char const &is: s) 
        {
          //cout << is << " vs1 " << vs1[ii] << ". ";
          if (vs2[ii] == is)
          {
            equal = true;
          }
          else
          {
            equal = false;
            break;
          }
            ii++;
        }
        //cout << endl;

        if (equal == true)
        {
          tt.games++;
          tt.goalScored = tt.goalScored + score[1];
          tt.goalAgainst = tt.goalAgainst + score[0];

          if (score[0] < score[1])
          {
            tt.wins++;
            tt.points = tt.points + 3;
          }
          else if (score[0] > score[1])
            tt.losses++;
          else if (score[0] == score[1])
          {
            tt.ties++;
            tt.points = tt.points + 1;
          }
          break;
        }

        //equal = true;
        ii = 0;
      }
      /*for (int k = 0; k < vs2.size(); k++)
        cout << vs2[k];
      cout << endl;
      cout << score[0] << "," << score[1] << endl;*/

      vs1.clear();
      vs2.clear();
    }

    for (auto& f: football)
    {
      f.goalDiff = f.goalScored - f.goalAgainst;
    }

    sort (football.begin(), football.end(), Sort);

    int num = 1;

    for (const auto& i: football)
    {
      cout << num << ") ";
      cout << i.name << " " << i.points << "p, " << i.games << "g (" << i.wins << "-" << i.ties << "-" << i.losses << "), " << i.goalDiff << "gd (" << i.goalScored << "-" << i.goalAgainst << ")\n";
      num++;
    }
    cout << endl;/**/

    football.clear();
  }
}
