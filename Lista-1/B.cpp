#include <iostream>

using namespace std;

int main()
{
  float c;
  while(cin >> c, c > 0.)
  {
    int n = 0;
    float l = 0;
    while (l < c)
    {
      n++;
      l += 1./(n+1);
    }
    cout << n << " card(s)" << endl;
  }

  return 0;
}
