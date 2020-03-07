#include <iostream>
#include <string>

using namespace std;

int main()
{
  string n;
  
  while (cin >> n, n.compare("0"))
  {
    while(n.size() > 1)
    {
      int fn = 0;
      string::iterator it;
      for (it = n.begin(); it != n.end(); it++) 
        fn += *it - '0';
      n = to_string(fn);
    }
    cout << n  << endl;
  }

  return 0;
}
