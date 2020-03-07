#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
  int t, n;
  cin >> t;

  while(t)
  {
    cin >> n;
    vector<int> x(n);
    for(int i = 0; i < n; i++)
      cin >> x[i];

    sort(x.begin(), x.end());
    int acc = x[n - 1] - x[0];
    for(int i = 0; i < n - 1; i++)
      acc += x[i + 1] - x[i];
    
    cout << acc << endl;

    t--;
  }

  return 0;
}