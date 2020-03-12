#include <iostream>
#include <string>

using namespace std;

int main()
{
  int n, l;
  string s;
  char r;
  cin >> n;

  while(n)
  {
    cin >> s;
    l = s.size();
    if(!s.compare("1") || !s.compare("4") ||  !s.compare("78"))
      r = '+';
    else if(s[l - 1] == '5' && s[l - 2] == '3')
      r = '-';
    else if(s[0] == '9' && s[l - 1] == '4')
      r = '*';
    else
      r = '?';
    
    cout << r << endl;
    n--;
  }

  return 0;
}