#include <iostream>
using namespace std;

int Sort(int arr[], int len)
{
  int swaps = 0;
  for(int i = 0; i < len-1; i++)
  {
    for(int j = i+1; j < len; j++)
    {
      if (arr[i] > arr[j])
      {
        swaps++;
      }
    }
  }
  return swaps;
}

int main() 
{
  int amt, nums;
  double total = 0;

  while (cin >> amt)
  {
    //cout << amt << endl;
    int arr[amt];
    for (int i = 0; i < amt; i++)
    {
      cin >> nums;
      arr[i] = nums;
      //cout << nums << " ";
    }

    cout << "Minimum exchange operations : " << Sort(arr, amt) << endl;
  }
}
