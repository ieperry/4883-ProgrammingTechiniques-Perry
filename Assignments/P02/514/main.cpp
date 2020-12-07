#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() 
{
  int mainnum, n;
  int count = 0;
  vector <int> main;
  vector <int> coaches;
  vector <int> train;
  vector <int> q;

  cin >> mainnum;
  //cout << mainnum << endl;
  while (mainnum != 0 || n != 0)
  {
    for (int i = 0; i < mainnum; i++)
      main.push_back(i+1);

    /*for (int i = 0; i < main.size(); i++)
      cout << main[i] << " ";
    cout << endl;*/

    cin >> n;
    while (n != 0)
    {
      //cout << n << " ";
      coaches.push_back(n);
      cin >> n;
      count++;
      if (count == mainnum)
      {
        /*for (int i = 0; i < coaches.size(); i++)
         cout << coaches[i] << " ";
        cout << endl;*/

        for (int k = 0; k < coaches.size(); k++)
        {
          if (coaches[0] != 1 && k == 0)
          {
            for (int i = 0; i < main.size(); i++)
            {
              if (main[i] == coaches[k])
              {
                train.push_back(coaches[k]);
                break;
              }
              else if (main[i] != coaches[k])
              {
                q.push_back(main[i]);
              }
            }

            /*for (int i = 0; i < train.size(); i++)
              cout << train[i] << " ";
            cout << endl;*/
          }
          else if (train[train.size()-1] < coaches[k])
          {
            //cout << train[train.size()-1] << " " << coaches[k] << endl;
            for (int i = 0; i < main.size(); i++)
            {
              if (main[i] == coaches[k])
              {
                train.push_back(coaches[k]);
                break;
              }
              else if (main[i] != coaches[k])
              {
                q.push_back(main[i]);
              }
            }

            /*for (int i = 0; i < train.size(); i++)
              cout << train[i] << " ";
            cout << endl;*/
          }
        }
        //check if q repeats in itself or contains nums from train
        for (int i = 0; i < q.size(); i++)
        {
          for (int j = 0; j < q.size(); j++)
          {
            if (i != j)
            {
              if (q[i] == q[j])
              {
                q[j] = -1;
              }
            }
          }
        }

        for (int i = 0; i < train.size(); i++)
        {
          for (int j = 0; j < q.size(); j++)
          {
            if (train[i] == q[j])
            {
              q[j] = -1;
            }
          }
        }
        //Go through coaches and try to match nums with nums in trains and q
        //Going through coaches, if num doesn't match in trains look at nums less than last num to find a match from q
        bool match;
        //cout << match << endl;
        for (int i = 0; i < coaches.size(); i++)
        {
          if (i < train.size())
          {
            if (coaches[i] == train[i])
              match = true;
            else if (coaches[i] != train[i])
            {
              int min = coaches[i-1];
              int k = q.size()-1;
              while (k >= 0)
              {
                if (q[k] != -1 && q[k] < min)
                {
                  if (q[k] == coaches[i])
                  {
                    match = true;
                    q[k] = -1;
                  }
                  else if (q[k] != coaches[i])
                  {
                    match = false;
                    break;
                  }
                }
                //cout << q[k] << " " << match << endl;
                k--;
              }
            }
          }
          else if (i >= train.size())
          {
            int k = q.size()-1;
            while (k >= 0)
            {
              if (q[k] != -1)
              {
                if (q[k] == coaches[i])
                {
                  match = true;
                  q[k] = -1;
                }
                else if (q[k] != coaches[i])
                {
                  match = false;
                  break;
                }
              }
              //cout << q[k] << " " << match << endl;
              k--;
            }
          }
        }
        
        if (match == true)
          cout << "Yes";
        else if (match == false)
          cout << "No";
        else
          cout <<  "?";

        /*cout << "q: ";
        for (int i = 0; i < q.size(); i++)
        {
          cout << q[i] << " ";
        }*/

        cout << endl;
        count = 0;
        q.clear();
        coaches.clear();
        train.clear();
      }
    } cout << endl;
    
    main.clear();
    cin >> mainnum;
    //cout << mainnum << endl;
  }
}
