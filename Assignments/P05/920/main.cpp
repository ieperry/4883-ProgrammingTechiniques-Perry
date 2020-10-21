#include <iostream>
#include <math.h>
#include <iomanip>
#include <queue> 
using namespace std;

double distance (vector <pair<double, double>> &pt, double maxpt, int ind)
{
  double changeX, changeY, squareX, squareY, sqRT;
  double valueY, slope, xSlope, mid, newX;
  //cout << maxpt << "  /  ";
  
  if (pt[ind].second > maxpt && pt[ind-1].second == maxpt)
  {
    changeX = pt[ind].first - pt[ind-1].first;
    changeY = pt[ind].second - pt[ind-1].second;
    //cout << changeX << " " << changeY << endl;
    squareX = changeX * changeX;
    squareY = changeY * changeY;
    //cout << squareX << " " << squareY << endl;
    sqRT = sqrt((squareX + squareY));
    return sqRT;
  }
  else if (pt[ind].second > maxpt && pt[ind-1].second != maxpt)
  {
    int i = ind;
    int ix = -1;
    while (i >= 0)
    {
      if (maxpt == pt[i].second)
        break;
      i--;
    }
    //cout << pt[i].second << " v " << pt[ind].second << endl;

    slope = ((pt[ind].second - pt[ind-1].second) / (pt[ind].first - pt[ind-1].first));
    valueY = pt[ind].second - pt[i].second;
    xSlope = pt[ind].first * slope;
    mid = ((-1 * xSlope) + valueY);
    newX = mid / (slope * -1);
    //cout << newX << endl;

    changeX = newX - pt[ind].first;
    changeY = maxpt - pt[ind].second;
    //cout << changeX << " " << changeY << endl;
    squareX = changeX * changeX;
    squareY = changeY * changeY;
    //cout << squareX << " " << squareY << endl;
    sqRT = sqrt((squareX + squareY));
    return sqRT;
  }
}

int main() 
{
  int cases, points;
  double x, y, maxpeak, total;
  priority_queue <pair<double, double>> pts;
  vector <pair<double, double>> calc;

  cin >> cases;
  //cout << cases;
  while (cases > 0)
  {
    cin >> points;
    for (int i = 0; i < points; i++)
    {
      cin >> x >> y;

      pts.push(make_pair(x, y));
    }

    while (!pts.empty())
    {
      calc.push_back(pts.top());
      pts.pop();
    }

    maxpeak = calc.front().second;
    total = 0;
    //cout << maxpeak << endl;
    for (int i = 1; i < calc.size(); i++)
    {
      if (calc[i].second > maxpeak)
      {
        total += distance(calc, maxpeak, i);
        maxpeak = calc[i].second;
      }
    }
    cout << fixed << setprecision(2) << total << endl;

    calc.clear();
    cases--;
    //cout << cases;
  }
}
