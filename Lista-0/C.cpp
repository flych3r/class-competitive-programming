#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

typedef pair<int, string> pis;

int unsortedness(string d)
{
  int u = 0;
  int s = d.size();
  for(int i = 0; i < s; i++)
  {
    for(int j = i+1; j < s; j++)
    {
      if(d[i] > d[j]) u++;
    }
  }
  
  return u;
}

bool comparator(pis a, pis b)
{
  return a.first < b.first;
}

int main()
{
  int n, m;
  cin >> n >> m;
  vector<pis> dnas(m);
  
  string d;
  int u;
  for(int i = 0; i < m; i++)
  {
    cin >> d;
    u = unsortedness(d);
    dnas[i] = make_pair(u, d);
  }

  stable_sort(dnas.begin(), dnas.end(), comparator);

  vector<pis>::iterator it;
  for (it = dnas.begin(); it != dnas.end(); it++) 
    cout << (*it).second << endl;  

  return 0;
}
